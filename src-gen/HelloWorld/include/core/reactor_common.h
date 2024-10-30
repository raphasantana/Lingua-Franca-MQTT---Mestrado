/**
 * @file
 * @author Edward A. Lee (eal@berkeley.edu)
 * @author Marten Lohstroh
 * @author Soroush Bateni
 * @author Mehrdad Niknami
 * @author Alexander Schulz-Rosengarten
 * @author Erling Rennemo Jellum
 * @copyright (c) 2020-2024, The University of California at Berkeley.
 * License: <a href="https://github.com/lf-lang/reactor-c/blob/main/LICENSE.md">BSD 2-clause</a>
 * @brief Declarations of functions with implementations in reactor.c and reactor_threaded.c.
 *
 * The functions declared in this file, as opposed to the ones in reactor.h, are not meant to be
 * called by application programmers. They should be viewed as private functions that make up the
 * C runtime.  In some cases, the implementation of these functions is in reactor_common.c, and in
 * other cases, alternative implementations are provided in reactor.c and reactor_threaded.c.
 * A third possibility is that the function is code generated.
 */

#ifndef REACTOR_COMMON_H
#define REACTOR_COMMON_H

#include "lf_types.h"
#include "environment.h"
#include "tag.h"
#include "pqueue.h"
#include "vector.h"
#include "util.h"
#include "modes.h"
#include "port.h"

//////////////////////  Constants & Macros  //////////////////////

/**
 * @brief Constant giving the minimum amount of time to sleep to wait
 * for physical time to reach a logical time.
 *
 * Unless the "fast" option is given, an LF program will wait until
 * physical time matches logical time before handling an event with
 * a given logical time. The amount of time is less than this given
 * threshold, then no wait will occur. The purpose of this is
 * to prevent unnecessary delays caused by simply setting up and
 * performing the wait.
 */
#define MIN_SLEEP_DURATION USEC(10)

//////////////////////  Global Variables  //////////////////////

// The following variables are defined in reactor_common.c and used in reactor.c,
// reactor_threaded.c, modes.c, and by the code generator.
extern bool _lf_normal_termination;
extern unsigned int _lf_number_of_workers;
extern int default_argc;
extern const char** default_argv;
extern instant_t duration;
extern bool fast;
extern bool keepalive_specified;

#ifdef FEDERATED_DECENTRALIZED
extern interval_t lf_fed_STA_offset;
#endif

// The following is defined by the code generator.
extern struct allocation_record_t* _lf_reactors_to_free;

//////////////////////  Functions  //////////////////////

/**
 * @brief Combine a deadline and a level into a single index for sorting in the reaction queue.
 *
 * This shifts the deadline right by 16 bits and inserts the level in the low-order 16 bits.
 * If the deadline is larger than `ULLONG_MAX >> 16`, then it is treated as the largest possible deadline.
 * @oaran deadline THe deadline.
 * @param level The level in the reaction graph.
 */
index_t lf_combine_deadline_and_level(interval_t deadline, int level);

/**
 * @brief Create and initialize the required number of environments for the program.
 * @note This function will be code generated by the compiler.
 */
void lf_create_environments(void);

/**
 * @brief Free memory on the specified allocation record (a self struct).
 *
 * This will mark the allocation record empty by setting `*head` to NULL.
 * If the argument is NULL, do nothing.
 *
 * @param head Pointer to the head of a list on which allocations are recorded.
 */
void lf_free(struct allocation_record_t** head);

/**
 * Get a new event. If there is a recycled event available, use that.
 * If not, allocate a new one. In either case, all fields will be zero'ed out.
 * @param env Environment in which we are executing.
 */
event_t* lf_get_new_event(environment_t* env);

/**
 * @brief Recycle the given event.
 *
 * This will zero out the event and push it onto the recycle queue.
 * @param env Environment in which we are executing.
 * @param e The event to recycle.
 */
void lf_recycle_event(environment_t* env, event_t* e);

/**
 * Replace the token on the specified event with the specified
 * token and free the old token.
 * @param event The event.
 * @param token The token.
 */
void lf_replace_token(event_t* event, lf_token_t* token);

/**
 * @brief Generated function that optionally sets default command-line options.
 */
void lf_set_default_command_line_options(void);

/**
 * @brief Perform whatever is needed to start a time step.
 *
 * For example, this function resets outputs to be absent at the start of a new time step.
 *
 * @param env The environment in which we are executing
 */
void _lf_start_time_step(environment_t* env);

/**
 * @brief Function that is called when the program is about to exit.
 *
 * This function will be invoked after all shutdown actions have completed.
 * For non-federated programs, the code generator generates an empty function to implement this.
 * For federated programs, the function is implemented in federate.c.
 *
 * @param env The environment in which we are executing
 */
void lf_terminate_execution(environment_t* env);

/**
 * Generated function that produces a table containing all triggers
 * (i.e., inputs, timers, and actions).
 */
void _lf_initialize_trigger_objects();

/**
 * @brief Perform final wrap-up on exit.
 *
 * This function will be registered to execute on exit.
 * It reports elapsed logical and physical times and reports if any
 * memory allocated for tokens has not been freed.
 */
void termination(void);

/**
 * @brief Trigger the specified reaction on the specified worker in the specified environment.
 * @param env Environment in which we are executing.
 * @param reaction The reaction.
 * @param worker_number The ID of the worker that is making this call. 0 should be
 *  used if there is only one worker (e.g., when the program is using the
 *  single-threaded C runtime). -1 is used for an anonymous call in a context where a
 *  worker number does not make sense (e.g., the caller is not a worker thread).
 */
void _lf_trigger_reaction(environment_t* env, reaction_t* reaction, int worker_number);

/**
 * @brief Initialize the given timer.
 * If this timer has a zero offset, enqueue the reactions it triggers.
 * If this timer is to trigger reactions at a _future_ tag as well,
 * schedule it accordingly.
 * @param env Environment in which we are executing.
 * @param timer The timer to initialize.
 */
void _lf_initialize_timer(environment_t* env, trigger_t* timer);

/**
 * @brief Initialize all the timers in the environment
 * @param env Environment in which we are executing.
 */
void _lf_initialize_timers(environment_t* env);

/**
 * @brief Trigger all the startup reactions in the specified environment.
 * @param env Environment in which we are executing.
 */
void _lf_trigger_startup_reactions(environment_t* env);

/**
 * @brief Trigger all the shutdown reactions in the specified environment.
 * @param env Environment in which we are executing.
 */
void _lf_trigger_shutdown_reactions(environment_t* env);

/**
 * @brief Create a dummy event with the specified tag.
 *
 * A dummy event is an event with no triggers that can be put on the event queue to trigger a tag advance to the
 * specified tag.
 * @param env Environment in which we are executing.
 * @param tag The tag of that event.
 * @return A pointer to the dummy event.
 */
event_t* _lf_create_dummy_events(environment_t* env, tag_t tag);

/**
 * @brief Schedule an event at a specific tag (time, microstep).
 *
 * If there is an event found at the requested tag, the payload
 * is replaced and 0 is returned.
 *
 * Note that this function is an internal API that must be called with a tag that is in the future
 * relative to the current tag (or the environment has not started executing). Also, it must be called
 * with tags that are in order for a given trigger. This means that the following order is illegal:
 * ```
 * _lf_schedule_at_tag(trigger1, bigger_tag, ...);
 * _lf_schedule_at_tag(trigger1, smaller_tag, ...);
 * ```
 * where `bigger_tag > smaller_tag`. This function is primarily
 * used for network communication (which is assumed to be in order).
 *
 * This function assumes the caller holds the mutex lock.
 *
 * @param env Environment in which we are executing.
 * @param trigger The trigger to be invoked at a later logical time.
 * @param tag Logical tag of the event
 * @param token The token wrapping the payload or NULL for no payload.
 *
 * @return A positive trigger handle for success, 0 if no new event was scheduled
 *  (instead, the payload was updated), or -1 for error (the tag is equal to or less
 *  than the current tag).
 */
trigger_handle_t _lf_schedule_at_tag(environment_t* env, trigger_t* trigger, tag_t tag, lf_token_t* token);

/**
 * @brief Insert reactions triggered by trigger to the reaction queue.
 * @param env Environment in which we are executing.
 * @param trigger The trigger.
 * @param token The token wrapping the payload or NULL for no payload.
 * @return 1 if successful, or 0 if no new reaction was scheduled because the function
 *  was called incorrectly.
 */
trigger_handle_t _lf_insert_reactions_for_trigger(environment_t* env, trigger_t* trigger, lf_token_t* token);

/**
 * Advance from the current tag to the next. If the given next_time is equal to
 * the current time, then increase the microstep. Otherwise, update the current
 * time and set the microstep to zero.
 * @param env The environment in which we are executing
 * @param next_tag The tag step to advance to.
 */
void _lf_advance_tag(environment_t* env, tag_t next_tag);

/**
 * @brief Pop all events from event_q with tag equal to current tag.
 *
 * This will extract all the reactions triggered by these events and stick them onto the
 * reaction queue.
 *
 * @param env The environment in which we are executing
 */
void _lf_pop_events(environment_t* env);

void _lf_invoke_reaction(environment_t* env, reaction_t* reaction, int worker);
void schedule_output_reactions(environment_t* env, reaction_t* reaction, int worker);
int process_args(int argc, const char* argv[]);

/**
 * @brief Initialize global variables and start tracing before calling the `_lf_initialize_trigger_objects` function.
 */
void initialize_global();

#endif