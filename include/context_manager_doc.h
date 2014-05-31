/*
 * Copyright (c) 2014 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * PROPRIETARY/CONFIDENTIAL
 *
 * This software is the confidential and proprietary information of SAMSUNG
 * ELECTRONICS ("Confidential Information"). You shall not disclose such
 * Confidential Information and shall use it only in accordance with the terms
 * of the license agreement you entered into with SAMSUNG ELECTRONICS. SAMSUNG
 * make no representations or warranties about the suitability of the software,
 * either express or implied, including but not limited to the implied
 * warranties of merchantability, fitness for a particular purpose, or
 * non-infringement. SAMSUNG shall not be liable for any damages suffered by
 * licensee as a result of using, modifying or distributing this software or
 * its derivatives.
 * licensee arising out of or related to this software.
 *
 */

#ifndef __TIZEN_SYSTEM_CONTEXT_MANAGER_DOC_H__
#define __TIZEN_SYSTEM_CONTEXT_MANAGER_DOC_H__

 /**
 * @defgroup CAPI_SYSTEM_CONTEXT_MANAGER_MODULE Context Manager
 * @brief The @ref CAPI_SYSTEM_CONTEXT_MANAGER_MODULE API provides functions to be notified
 * if a context data is updated, or to get the current context data.
 * @ingroup CAPI_SYSTEM_FRAMEWORK
 *
 * @section CAPI_SYSTEM_CONTEXT_MANAGER_MODULE_HEADER Required Header
 *   \#include <context_manager.h>
 *
 * @section CAPI_SYSTEM_CONTEXT_MANAGER_MODULE_OVERVIEW Overview
 * To be notified with any updated context data, an application needs to register
 * a callback function for the context item.
 * In addition to the functionality of registering update callbacks,
 * in cases of some context items, Context Manager also provides the functionalities
 * of getting the current context information and setting context-item-specific options.@n
 * The following example shows how to set the callback function for #CONTEXT_ITEM_PEDOMETER.

 \code{.cpp}
	int req_id;
	int result;
	result = context_set_changed_callback(CONTEXT_ITEM_PEDOMETER, NULL, context_update_cb, NULL, &req_id);
 \endcode

 * \anchor option_rules \attention
 * Note that the @c option for #CONTEXT_ITEM_PEDOMETER is not allowed to be changed by the other applications,
 * except the core pedometer application and S-Health.
 * #CONTEXT_ITEM_PEDOMETER has three option values, gender, height, and weight.
 * Such values should be unique in a device.
 * In the above example, the @c option parameter is thus set to @c NULL.@n
 *
 *
 * If an option is not specified, the previously specified value is used implicitly.
 * However, if no such value exists, i.e., the option value hasn't been specified since the device is turned on,
 * the default value is used. For the default values, please see context_manager_types.h.
 *
 * After setting the callback function, if necessary, the application can request the current pedometer status
 * by using context_get_context().

 \code{.cpp}
     int req_id;
     int result = context_get_context(CONTEXT_ITEM_PEDOMETER, NULL, context_update_cb, NULL, &req_id);
 \endcode

 * The callback function does not need to be the same function passed to context_set_changed_callback().@n
 *
 * An example callback function is as follows:

 \code{.cpp}
 void context_update_cb(int error, context_item_e context, char* context_data, void* user_data, int req_id)
 {
     double dist, cal, step;

     if (error == CONTEXT_ERROR_NONE) {
         if (context == CONTEXT_ITEM_PEDOMETER) {
             context_context_data_get_double(context_data, CONTEXT_PEDOMETER_CUMULATIVE_DISTANCE, &dist);
             context_context_data_get_double(context_data, CONTEXT_PEDOMETER_CUMULATIVE_CALORIE, &cal);
             context_context_data_get_double(context_data, CONTEXT_PEDOMETER_CUMULATIVE_TOTAL_STEP_COUNT, &step);

             printf("Distance: %.2f, Calorie: %.2f, Step Count: %.0f", dist, cal, step);

             free(context_data);
         }
     }
 }
 \endcode

 * Context data values can be extracted from the @c context_data parameter by using
 * context_context_data_get_int(), context_context_data_get_double(), and context_context_data_get_str() functions.@n
 *
 * To unset the callback function registered by context_set_changed_callback(), context_unset_changed_callback()
 * needs to be called.
 *
 * The list of available context items are described below:
 * <div>
 *  <table class="doxtable">
 *  <tr>
 *      <th>Context Item</th>
 *      <th>Description</th>
 *      <th>Notification</th>
 *      <th>Available Option</th>
 *      <th>Context Data Key (Type)</th>
 *  </tr>
 *  <tr>
 *      <td>#CONTEXT_ITEM_WRIST_UP</td>
 *      <td>Notify when wrist-up gesture occurs</td>
 *      <td>One shot</td>
 *      <td>None</td>
 *      <td>#CONTEXT_MOTION_ACTION (#context_wrist_up_action)</td>
 *  </tr>
 *  <tr>
 *      <td>#CONTEXT_ITEM_PEDOMETER</td>
 *      <td>Notify when pedestrian status is changed</td>
 *      <td>When LCD is on, notify when changed; when LCD off, notify every 20min with log of changed pedometer data</td>
 *      <td>#CONTEXT_PEDOMETER_GENDER (#context_pedometer_gender), #CONTEXT_PEDOMETER_HEIGHT, #CONTEXT_PEDOMETER_WEIGHT</td>
 *      <td>#CONTEXT_PEDOMETER_STEP_STATUS (#context_pedometer_step_status), #CONTEXT_PEDOMETER_SPEED, #CONTEXT_PEDOMETER_WALKING_FREQUENCY,
 *			#CONTEXT_PEDOMETER_CUMULATIVE_DISTANCE, #CONTEXT_PEDOMETER_CUMULATIVE_CALORIE, #CONTEXT_PEDOMETER_CUMULATIVE_TOTAL_STEP_COUNT,
 *			#CONTEXT_PEDOMETER_CUMULATIVE_WALK_STEP_COUNT, #CONTEXT_PEDOMETER_CUMULATIVE_WALK_UP_STEP_COUNT, #CONTEXT_PEDOMETER_CUMULATIVE_WALK_DOWN_STEP_COUNT,
 *			#CONTEXT_PEDOMETER_CUMULATIVE_RUN_STEP_COUNT, #CONTEXT_PEDOMETER_CUMULATIVE_RUN_UP_STEP_COUNT, #CONTEXT_PEDOMETER_CUMULATIVE_RUN_DOWN_STEP_COUNT,
 *			#CONTEXT_PEDOMETER_LOG_COUNT, #CONTEXT_PEDOMETER_DISTANCE_DIFF, #CONTEXT_PEDOMETER_CALORIE_DIFF, #CONTEXT_PEDOMETER_TOTAL_STEP_COUNT_DIFF,
 *			#CONTEXT_PEDOMETER_WALK_STEP_COUNT_DIFF, #CONTEXT_PEDOMETER_WALK_UP_STEP_COUNT_DIFF, #CONTEXT_PEDOMETER_WALK_DOWN_STEP_COUNT_DIFF,
 *			#CONTEXT_PEDOMETER_RUN_STEP_COUNT_DIFF, #CONTEXT_PEDOMETER_RUN_UP_STEP_COUNT_DIFF, #CONTEXT_PEDOMETER_RUN_DOWN_STEP_COUNT_DIFF,
 *			#CONTEXT_PEDOMETER_SPEED_LOG
 *      </td>
 *  </tr>
 *  <tr>
 *      <td>#CONTEXT_ITEM_MOVEMENT_ALERT</td>
 *      <td>Notify when there is no movement for a while</td>
 *      <td>First notify when there is no movement (about 3 sec); After that notify whenever there is movement or no movement.</td>
 *      <td>None</td>
 *      <td>#CONTEXT_MOTION_ACTION (#context_movement_alert_action)</td>
 *  </tr>
 *  <tr>
 *      <td>#CONTEXT_ITEM_AUTO_ROTATION</td>
 *      <td>Notify when device orientation is changed</td>
 *      <td>When LCD is on, notify when changed; When LCD off, no notification is provided.</td>
 *      <td>#CONTEXT_AUTO_ROTATION_DEVICE_TYPE (#context_auto_rotation_device_type)</td>
 *      <td>#CONTEXT_MOTION_ANGLE (#context_auto_rotation_angle)</td>
 *  </tr>
 *  <tr>
 *      <td>#CONTEXT_ITEM_MOVEMENT</td>
 *      <td>Notify when there is movement</td>
 *      <td>One shot</td>
 *      <td>None</td>
 *      <td>#CONTEXT_MOTION_ACTION (#context_movement_action)</td>
 *  </tr>
 *  <tr>
 *      <td>#CONTEXT_ITEM_SHAKE_MOTION</td>
 *      <td>Notify when shake motion starts/stops</td>
 *      <td>Notify when shake motion starts/stops</td>
 *      <td>#CONTEXT_SHAKE_MOTION_STRENGTH, #CONTEXT_SHAKE_MOTION_DURATION</td>
 *      <td>#CONTEXT_MOTION_ACTION (#context_shake_motion_action)</td>
 *  </tr>
 *  <tr>
 *      <td>#CONTEXT_ITEM_HRM_ALWAYS_ON</td>
 *      <td>Notify HRM(Heart Rate Monitor) continuously</td>
 *      <td>Notify every 100 msec</td>
 *      <td>None</td>
 *      <td>#CONTEXT_HRM_SPO2, #CONTEXT_HRM_HEART_RATE, #CONTEXT_HRM_PEAK_TO_PEAK, #CONTEXT_HRM_SNR</td>
 *  </tr>
 *  <tr>
 *      <td>#CONTEXT_ITEM_HRM</td>
 *      <td>Notify HRM(Heart Rate Monitor) adaptive to LCD on/off status</td>
 *      <td>When LCD is on, notify every 100 msec; When LCD off, notify log of HRM data (in array format) every 30 seconds.</td>
 *      <td>None</td>
 *      <td>#CONTEXT_HRM_SPO2, #CONTEXT_HRM_HEART_RATE, #CONTEXT_HRM_PEAK_TO_PEAK, #CONTEXT_HRM_SNR</td>
 *  </tr>
 *  <tr>
 *      <td>#CONTEXT_ITEM_SLEEP_MONITOR</td>
 *      <td>Notify sleep status log every 20 minutes (Manual sleep monitor)</td>
 *      <td>Notify sleep status log every 20 minutes</td>
 *      <td>#CONTEXT_SLEEP_MONITOR_SENSIBILITY, #CONTEXT_SLEEP_MONITOR_SAMPLING_INTERVAL</td>
 *      <td>#CONTEXT_SLEEP_MONITOR_STATUS (#context_sleep_monitor_status)</td>
 *  </tr>
 *  <tr>
 *      <td>#CONTEXT_ITEM_SLEEP_MONITOR_EXT</td>
 *      <td>Notify sleep status log every 20 minutes with extra data for automatic sleep duration detection.
 *          The extra data is specific to Samsung's proprietary auto sleep duration detection algorithm.</td>
 *      <td>Notify log data every 20 minutes</td>
 *      <td>#CONTEXT_SLEEP_MONITOR_SENSIBILITY, #CONTEXT_SLEEP_MONITOR_SAMPLING_INTERVAL</td>
 *      <td>#CONTEXT_SLEEP_MONITOR_STATUS (#context_sleep_monitor_status), #CONTEXT_SLEEP_MONITOR_PIM,
 *      	#CONTEXT_SLEEP_MONITOR_ZCM, #CONTEXT_SLEEP_MONITOR_STAGE, #CONTEXT_SLEEP_MONITOR_WRIST,
 *      	#CONTEXT_SLEEP_MONITOR_FLAG
 *      </td>
 *  </tr>
 *  <tr>
 *      <td>#CONTEXT_ITEM_ACTIVITY_NOTIFICATION</td>
 *      <td>Notify when specified activity occurs</td>
 *      <td>Notify when specified activity occurs</td>
 *      <td>#CONTEXT_ACTIVITY_NOTIFICATION_ACTIVITY_FILTER</td>
 *      <td>#CONTEXT_ACTIVITY_STATUS (#context_activity_status), #CONTEXT_ACTIVITY_ACCURACY (#context_activity_accuracy)</td>
 *  </tr>
 *  </table>
 * </div>
 */

#endif // __TIZEN_SYSTEM_CONTEXT_MANAGER_DOC_H__
