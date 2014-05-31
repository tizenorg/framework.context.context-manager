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

/**
 * @addtogroup CAPI_SYSTEM_CONTEXT_MANAGER_MODULE
 * @{
 */

/**
 * @file	context_manager_types.h
 * @brief	This is the header file to define types of the context manager.
 */

#ifndef __TIZEN_SYSTEM_CONTEXT_MANAGER_TYPES_H__
#define __TIZEN_SYSTEM_CONTEXT_MANAGER_TYPES_H__

#include <sys/types.h>
#include <tizen_error.h>

/**
 * @brief	Error codes for Context Manager.
 */
typedef enum {
	CONTEXT_ERROR_NONE						= TIZEN_ERROR_NONE,					/**< Successful */
	CONTEXT_ERROR_INVALID_PARAMETER			= TIZEN_ERROR_INVALID_PARAMETER,	/**< Invalid parameter */
	CONTEXT_ERROR_INVALID_OPERATION			= TIZEN_ERROR_INVALID_OPERATION,	/**< Invalid operation */
	CONTEXT_ERROR_OPERATION_FAILED			= TIZEN_ERROR_SYSTEM_CLASS | 0x01,	/**< Operation failed because of a system error. */
	CONTEXT_ERROR_CONTEXT_NOT_REGISTERED		= TIZEN_ERROR_SYSTEM_CLASS | 0x02,	/**< The context item needs to be registered, but not registered yet. */
	CONTEXT_ERROR_CONTEXT_ALREADY_REGISTERED	= TIZEN_ERROR_SYSTEM_CLASS | 0x03,	/**< The context item is already registered. */
	CONTEXT_ERROR_CONTEXT_NOT_ENABLED		= TIZEN_ERROR_SYSTEM_CLASS | 0x02,	/**< Deprecated. The context item needs to be registered, but not registered yet. */
	CONTEXT_ERROR_CONTEXT_ALREADY_ENABLED	= TIZEN_ERROR_SYSTEM_CLASS | 0x03,	/**< Deprecated. The context item is already registered. */
	CONTEXT_ERROR_UNSUPPORTED_OPERATION		= TIZEN_ERROR_SYSTEM_CLASS | 0x04,	/**< Unsupported operation for the context item. */
	CONTEXT_ERROR_UNSUPPORTED_CONTEXT		= TIZEN_ERROR_SYSTEM_CLASS | 0x05,	/**< The context item exists, but not supported in the current profile. */
	CONTEXT_ERROR_INVALID_CONTEXT			= TIZEN_ERROR_SYSTEM_CLASS | 0x06,	/**< Invalid context item */
	CONTEXT_ERROR_UNSUPPORTED_OPTION		= TIZEN_ERROR_SYSTEM_CLASS | 0x07,	/**< Unsupported option key for the context item */
	CONTEXT_ERROR_INVALID_OPTION			= TIZEN_ERROR_SYSTEM_CLASS | 0x08,	/**< Invalid option value for the key */
} context_error_e;

/**
 * @brief	Context item classes.
 */
enum context_item_class {
	CONTEXT_ITEM_CLASS_MOTION		= 0x00010000,	/**< Motion context class */
	CONTEXT_ITEM_CLASS_ACTIVITY		= 0x00020000,	/**< Activity context class */
};

/**
 * @brief	Context Items.
 */
typedef enum {
	CONTEXT_ITEM_WRIST_UP		= CONTEXT_ITEM_CLASS_MOTION | 0x0001,	/**< Wrist-up gesture */
	CONTEXT_ITEM_PEDOMETER		= CONTEXT_ITEM_CLASS_MOTION | 0x0002,	/**< Pedestrian status */
	CONTEXT_ITEM_MOVEMENT_ALERT	= CONTEXT_ITEM_CLASS_MOTION | 0x0003,	/**< Movement-alert */
	CONTEXT_ITEM_AUTO_ROTATION	= CONTEXT_ITEM_CLASS_MOTION | 0x0004,	/**< Device's rotation */
	CONTEXT_ITEM_MOVEMENT		= CONTEXT_ITEM_CLASS_MOTION | 0x0005,	/**< Movement */
	CONTEXT_ITEM_SHAKE_MOTION	= CONTEXT_ITEM_CLASS_MOTION | 0x0006,	/**< Shake motion */
	CONTEXT_ITEM_HRM_ALWAYS_ON	= CONTEXT_ITEM_CLASS_MOTION | 0x0007,	/**< Heart rate monitor */
	CONTEXT_ITEM_SLEEP_MONITOR	= CONTEXT_ITEM_CLASS_MOTION | 0x0008,	/**< Sleep monitor */
	CONTEXT_ITEM_SLEEP_MONITOR_EXT	= CONTEXT_ITEM_CLASS_MOTION | 0x0009,	/**< Sleep monitor (extended) */
	CONTEXT_ITEM_HRM			= CONTEXT_ITEM_CLASS_MOTION | 0x000A,	/**< Heart rate monitor (Batch Mode) */
	CONTEXT_ITEM_HRM_EXT		= CONTEXT_ITEM_HRM,						/**< Please use  #CONTEXT_ITEM_HRM instead */
	CONTEXT_ITEM_ACTIVITY_NOTIFICATION	= CONTEXT_ITEM_CLASS_ACTIVITY | 0x0001,	/**< Activity notification */
} context_item_e;

/**
 * @brief	#CONTEXT_ITEM_WRIST_UP provides #CONTEXT_MOTION_ACTION with one of following values.
 */
enum context_wrist_up_action {
	CONTEXT_WRIST_UP_NONE = 0,	/**< No action detected */
	CONTEXT_WRIST_UP_NORMAL		/**< Wrist-up gesture detected */
};

/**
 * @brief	#CONTEXT_ITEM_MOVEMENT_ALERT provides #CONTEXT_MOTION_ACTION with one of following values.
 */
enum context_movement_alert_action {
	CONTEXT_MOVEMENT_ALERT_UNKNOWN = 0,	/**< Unknown */
	CONTEXT_MOVEMENT_ALERT_MOVE,		/**< Move */
	CONTEXT_MOVEMENT_ALERT_NO_MOVE		/**< No move */
};

/**
 * @brief	#CONTEXT_ITEM_MOVEMENT provides #CONTEXT_MOTION_ACTION with one of following values.
 */
enum context_movement_action {
	CONTEXT_MOVEMENT_NONE = 0,	/**< No action detected */
	CONTEXT_MOVEMENT_ACTION		/**< Movement action detected */
};

/**
 * @brief	Gender option values for #CONTEXT_ITEM_PEDOMETER.
 */
enum context_pedometer_gender {
	CONTEXT_PEDOMETER_GENDER_MALE	= 1,	/**< Male */
	CONTEXT_PEDOMETER_GENDER_FEMALE	= 2		/**< Female */
};

/**
 * @brief	#CONTEXT_ITEM_AUTO_ROTATION provides #CONTEXT_MOTION_ANGLE with one of following values.
 */
enum context_auto_rotation_angle {
	CONTEXT_AUTO_ROTATION_NONE	= -1,	/**< Rotation status unknown */
	CONTEXT_AUTO_ROTATION_0		= 0,	/**< Not rotated */
	CONTEXT_AUTO_ROTATION_90	= 1,	/**< 90 degrees */
	CONTEXT_AUTO_ROTATION_180	= 2,	/**< 180 degrees */
	CONTEXT_AUTO_ROTATION_270	= 3		/**< 270 degrees */
};

/**
 * @brief	Device type option values for #CONTEXT_ITEM_AUTO_ROTATION.
 */
enum context_auto_rotation_device_type {
	CONTEXT_AUTO_ROTATION_DEVICE_TYPE_MOBILE		= 0,	/**< Mobile */
	CONTEXT_AUTO_ROTATION_DEVICE_TYPE_TABLET		= 2,	/**< Tablet */
	CONTEXT_AUTO_ROTATION_DEVICE_TYPE_WIDE_TABLET	= 4		/**< Wide tablet */
};

/**
 * @brief	Exercise mode option/data values for #CONTEXT_ITEM_HRM.
 */
enum context_hrm_exercise_mode {
	CONTEXT_HRM_EXERCISE_MODE_HRM_OFF	= 0,	/**< Only the step distance will be traced */
	CONTEXT_HRM_EXERCISE_MODE_HRM_ON	= 1,	/**< HR and step distance will be traced together */
	CONTEXT_HRM_EXERCISE_MODE_HR_ONLY	= 2		/**< For Heart Rate Motnior app */
};

/**
 * @brief	#CONTEXT_ITEM_SHAKE_MOTION provides #CONTEXT_MOTION_ACTION with one of following values.
 */
enum context_shake_motion_action {
	CONTEXT_SHAKE_MOTION_NONE = 0,	/**< No motion detected */
	CONTEXT_SHAKE_MOTION_START,		/**< Shake motion started */
	CONTEXT_SHAKE_MOTION_STOP		/**< Shake motion stopped */
};

/**
 * @brief	#CONTEXT_ITEM_PEDOMETER provides #CONTEXT_PEDOMETER_STEP_STATUS with one of following values.
 */
enum context_pedometer_step_status {
	CONTEXT_PEDOMETER_STEP_STATUS_UNKNOWN = -1,	/**< Unknown walking statue */
	CONTEXT_PEDOMETER_STEP_STATUS_STOP,			/**< Not moving */
	CONTEXT_PEDOMETER_STEP_STATUS_MARK,			/**< Marking */
	CONTEXT_PEDOMETER_STEP_STATUS_STROLL,		/**< Strolling */
	CONTEXT_PEDOMETER_STEP_STATUS_WALK,			/**< Walking */
	CONTEXT_PEDOMETER_STEP_STATUS_RUN,			/**< Running */
	CONTEXT_PEDOMETER_STEP_STATUS_RUSH,			/**< Rushing */
	CONTEXT_PEDOMETER_STEP_STATUS_WALK_UP,		/**< Walking up */
	CONTEXT_PEDOMETER_STEP_STATUS_WALK_DOWN,	/**< Walking down */
	CONTEXT_PEDOMETER_STEP_STATUS_RUN_UP,		/**< Running up */
	CONTEXT_PEDOMETER_STEP_STATUS_RUN_DOWN		/**< Running down */
};

/**
 * @brief	#CONTEXT_ITEM_PEDOMETER provides #CONTEXT_PEDOMETER_MODE with one of following values.
 */
enum context_pedometer_mode {
	CONTEXT_PEDOMETER_MODE_NORMAL = 0,	/**< Normal mode */
	CONTEXT_PEDOMETER_MODE_LOGGING,		/**< Logging mode */
};

/**
 * @brief	#CONTEXT_ITEM_SLEEP_MONITOR provides #CONTEXT_SLEEP_MONITOR_STATUS with one of following values.
 */
enum context_sleep_monitor_status {
	CONTEXT_SLEEP_MONITOR_STATUS_UNKNOWN = -1,	/**< Unknown status */
	CONTEXT_SLEEP_MONITOR_STATUS_SLEEP,			/**< Sleep */
	CONTEXT_SLEEP_MONITOR_STATUS_WAKE			/**< Awake */
};

/**
 * @brief	#CONTEXT_ITEM_ACTIVITY_NOTIFICATION provides #CONTEXT_ACTIVITY_STATUS with one of following values.
 */
enum context_activity_status {
	CONTEXT_ACTIVITY_STATUS_UNKNOWN = 0,	/**< Unknown */
	CONTEXT_ACTIVITY_STATUS_STATIONARY,		/**< Stationary */
	CONTEXT_ACTIVITY_STATUS_WALK,			/**< Walking */
	CONTEXT_ACTIVITY_STATUS_RUN,			/**< Running */
	CONTEXT_ACTIVITY_STATUS_VEHICLE,		/**< In a moving vehicle */
	CONTEXT_ACTIVITY_STATUS_ALL,			/**< All above */
};

/**
 * @brief	#CONTEXT_ITEM_ACTIVITY_NOTIFICATION provides #CONTEXT_ACTIVITY_ACCURACY with one of following values.
 */
enum context_activity_accuracy {
	CONTEXT_ACTIVITY_ACCURACY_LOW = 0,	/**< Not accurate */
	CONTEXT_ACTIVITY_ACCURACY_MID,		/**< Moderately accurate  */
	CONTEXT_ACTIVITY_ACCURACY_HIGH,		/**< Highly accurate */
};


/**
 * @brief	Gender option key of Integer type for #CONTEXT_ITEM_PEDOMETER.
 * @details	It can be either #CONTEXT_PEDOMETER_GENDER_MALE or #CONTEXT_PEDOMETER_GENDER_FEMALE,
 *			and the default is #CONTEXT_PEDOMETER_GENDER_MALE.
 */
extern const char CONTEXT_PEDOMETER_GENDER[];

/**
 * @brief	Height option key of Double type for #CONTEXT_ITEM_PEDOMETER.
 * @details	Its valid range is [1, 300] in cm, and the default is 170 cm.
 */
extern const char CONTEXT_PEDOMETER_HEIGHT[];

/**
 * @brief	Weight option key of Double type for #CONTEXT_ITEM_PEDOMETER.
 * @details	Its valid range is [1, 500] in kg, and the default is 60 kg.
 */
extern const char CONTEXT_PEDOMETER_WEIGHT[];

/**
 * @brief	Device type option key of Integer type for #CONTEXT_ITEM_AUTO_ROTATION.
 * @details	It can be one of #CONTEXT_AUTO_ROTATION_DEVICE_TYPE_MOBILE, #CONTEXT_AUTO_ROTATION_DEVICE_TYPE_TABLET,
 *			or #CONTEXT_AUTO_ROTATION_DEVICE_TYPE_WIDE_TABLET.
 *			The default is #CONTEXT_AUTO_ROTATION_DEVICE_TYPE_MOBILE.
 */
extern const char CONTEXT_AUTO_ROTATION_DEVICE_TYPE[];

/**
 * @brief	Shake strength option key of Integer type for #CONTEXT_ITEM_SHAKE_MOTION.
 * @details	Its valid range is [1, 5], and the default is 2.
 */
extern const char CONTEXT_SHAKE_MOTION_STRENGTH[];

/**
 * @brief	Shake duration option key of Integer type for #CONTEXT_ITEM_SHAKE_MOTION.
 * @details	Its valid range is [1, 5000] in ms, and the default is 800 ms.
 */
extern const char CONTEXT_SHAKE_MOTION_DURATION[];

/**
 * @brief	Sensibility option key of Integer type for #CONTEXT_ITEM_SLEEP_MONITOR and #CONTEXT_ITEM_SLEEP_MONITOR_EXT.
 * @details	Positive integer, and the default is 80.
 */
extern const char CONTEXT_SLEEP_MONITOR_SENSIBILITY[];

/**
 * @brief	Sampling interval option key of Integer type for #CONTEXT_ITEM_SLEEP_MONITOR and #CONTEXT_ITEM_SLEEP_MONITOR_EXT.
 * @details	Positive integer, and the default is 100.
 */
extern const char CONTEXT_SLEEP_MONITOR_SAMPLING_INTERVAL[];

/**
 * @brief	Activity filter option key of Integer array type for #CONTEXT_ITEM_ACTIVITY_NOTIFICATION.
 * @details	An array of #context_activity_status values to represent the list of to-be-notified activities.
 *			Default is null.
 */
extern const char CONTEXT_ACTIVITY_NOTIFICATION_ACTIVITY_FILTER[];

/**
 * @brief	Exercise mode option/data key of Integer type for #CONTEXT_ITEM_HRM.
 * @details	It can be one of #CONTEXT_HRM_EXERCISE_MODE_HRM_OFF or #CONTEXT_HRM_EXERCISE_MODE_HRM_ON.@n
 *			When it is used as an option key, the default is #CONTEXT_HRM_EXERCISE_MODE_HRM_ON.
 *			An application also can use this key to extract the exercise mode from the received context data.
 * @remark	#CONTEXT_HRM_EXERCISE_MODE is effective only if no application is using #CONTEXT_ITEM_HRM.
 *			Otherwise, it is overrided by the mode designated by the application
 *			that has set a callback for #CONTEXT_ITEM_HRM first.
 */
extern const char CONTEXT_HRM_EXERCISE_MODE[];

/**
 * @brief	Action data key of Integer type for context data.
 * @details Context items, including #CONTEXT_ITEM_WRIST_UP, #CONTEXT_ITEM_MOVEMENT,
 *			#CONTEXT_ITEM_MOVEMENT_ALERT, and #CONTEXT_ITEM_SHAKE_MOTION, use this key for context data.
 * @see	context_wrist_up_action
 * @see	context_movement_action
 * @see	context_movement_alert_action
 * @see	context_shake_motion_action
 */
extern const char CONTEXT_MOTION_ACTION[];

/**
 * @brief	Rotated angle data key of Integer type for #CONTEXT_ITEM_AUTO_ROTATION data.
 * @details	Its value will be one of #context_auto_rotation_angle.
 */
extern const char CONTEXT_MOTION_ANGLE[];

/**
 * @brief	Step status data key of Integer type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value will be one of #context_pedometer_step_status.
 */
extern const char CONTEXT_PEDOMETER_STEP_STATUS[];

/**
 * @brief	Current speed (km/h) data key of Double type for #CONTEXT_ITEM_PEDOMETER data.
 */
extern const char CONTEXT_PEDOMETER_SPEED[];

/**
 * @brief	Walking frequency (steps per sec.) data key of Double type for #CONTEXT_ITEM_PEDOMETER data.
 */
extern const char CONTEXT_PEDOMETER_WALKING_FREQUENCY[];

/**
 * @brief	Distance (m) data key of Double type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the cumulative distance traveled since the last reboot.
 */
extern const char CONTEXT_PEDOMETER_CUMULATIVE_DISTANCE[];

/**
 * @brief	Calorie (kcal) data key of Double type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the cumulative calories burned since the last reboot.
 */
extern const char CONTEXT_PEDOMETER_CUMULATIVE_CALORIE[];

/**
 * @brief	Total step count data key of Double type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the cumulative step count since the last reboot.
 *			It is the sum of the walk and the run counts.
 */
extern const char CONTEXT_PEDOMETER_CUMULATIVE_TOTAL_STEP_COUNT[];

/**
 * @brief	Walking (flat) step count data key of Double type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the cumulative walking (flat) step count since the last reboot.
 */
extern const char CONTEXT_PEDOMETER_CUMULATIVE_WALK_STEP_COUNT[];

/**
 * @brief	Walking-up step count data key of Double type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the cumulative walking-up step count since the last reboot.
 */
extern const char CONTEXT_PEDOMETER_CUMULATIVE_WALK_UP_STEP_COUNT[];

/**
 * @brief	Walking-down step count data key of Double type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the cumulative walking-down step count since the last reboot.
 */
extern const char CONTEXT_PEDOMETER_CUMULATIVE_WALK_DOWN_STEP_COUNT[];

/**
 * @brief	Running (flat) step count data key of Double type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the cumulative running (flat) step count since the last reboot.
 */
extern const char CONTEXT_PEDOMETER_CUMULATIVE_RUN_STEP_COUNT[];

/**
 * @brief	Running-up step count data key of Double type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the cumulative running-up step count since the last reboot.
 */
extern const char CONTEXT_PEDOMETER_CUMULATIVE_RUN_UP_STEP_COUNT[];

/**
 * @brief	Running-down step count data key of Double type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the cumulative running-down step count since the last reboot.
 */
extern const char CONTEXT_PEDOMETER_CUMULATIVE_RUN_DOWN_STEP_COUNT[];

/**
 * @brief	Pedometer log count data key of Integer type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the number of elements in each Pedometer log data array(#CONTEXT_PEDOMETER_DISTANCE_DIFF,
 *			#CONTEXT_PEDOMETER_CALORIE_DIFF, #CONTEXT_PEDOMETER_TOTAL_STEP_COUNT_DIFF, #CONTEXT_PEDOMETER_WALK_STEP_COUNT_DIFF,
 *			#CONTEXT_PEDOMETER_WALK_UP_STEP_COUNT_DIFF, #CONTEXT_PEDOMETER_WALK_DOWN_STEP_COUNT_DIFF, #CONTEXT_PEDOMETER_RUN_STEP_COUNT_DIFF,
 *			#CONTEXT_PEDOMETER_RUN_UP_STEP_COUNT_DIFF, #CONTEXT_PEDOMETER_RUN_DOWN_STEP_COUNT_DIFF, #CONTEXT_PEDOMETER_SPEED_LOG).
 */
extern const char CONTEXT_PEDOMETER_LOG_COUNT[];

/**
 * @brief	Distance diff log data key of Double array type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the log of distance differences since the last notification.
 *			It has the size of #CONTEXT_PEDOMETER_LOG_COUNT.
 *
 *			When LCD is on, it contains only one diff value from last notification, since Context Manager notifies whenever pedestrian status is changed.
 *			However, when LCD is off, notification occurs every 20 minutes with the log of pedestrian status changes.
 *			When there is no change in last 20 minutes, it contains one value, 0.0.
 *			Since pedestrian status is estimated in the unit of minutes, the array has at most 20 elements.
 */
extern const char CONTEXT_PEDOMETER_DISTANCE_DIFF[];

/**
 * @brief	Calorie diff log data key of Double array type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the log of calorie differences since the last notification.
 *			It has the size of #CONTEXT_PEDOMETER_LOG_COUNT.
 *
 *			When LCD is on, it contains only one diff value from last notification, since Context Manager notifies whenever pedestrian status is changed.
 *			However, when LCD is off, notification occurs every 20 minutes with the log of pedestrian status changes.
 *			When there is no change in last 20 minutes, it contains one value, 0.0.
 *			Since pedestrian status is estimated in the unit of minutes, the array has at most 20 elements.
 */
extern const char CONTEXT_PEDOMETER_CALORIE_DIFF[];

/**
 * @brief	Total step count diff log data key of Integer array type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the log of total step count differences since the last notification.
 *			It has the size of #CONTEXT_PEDOMETER_LOG_COUNT.
 *
 *			When LCD is on, it contains only one diff value from last notification, since Context Manager notifies whenever pedestrian status is changed.
 *			However, when LCD is off, notification occurs every 20 minutes with the log of pedestrian status changes.
 *			When there is no change in last 20 minutes, it contains one value, 0.
 *			Since pedestrian status is estimated in the unit of minutes, the array has at most 20 elements.
 */
extern const char CONTEXT_PEDOMETER_TOTAL_STEP_COUNT_DIFF[];

/**
 * @brief	Walk (flat) step count diff log data key of Integer array type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the log of walk (flat) step count differences since the last notification.
 *			It has the size of #CONTEXT_PEDOMETER_LOG_COUNT.
 *
 *			When LCD is on, it contains only one diff value from last notification, since Context Manager notifies whenever pedestrian status is changed.
 *			However, when LCD is off, notification occurs every 20 minutes with the log of pedestrian status changes.
 *			When there is no change in last 20 minutes, it contains one value, 0.
 *			Since pedestrian status is estimated in the unit of minutes, the array has at most 20 elements.
 */
extern const char CONTEXT_PEDOMETER_WALK_STEP_COUNT_DIFF[];

/**
 * @brief	Walk up step count diff log data key of Integer array type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the log of walk up step count differences since the last notification.
 *			It has the size of #CONTEXT_PEDOMETER_LOG_COUNT.
 *
 *			When LCD is on, it contains only one diff value from last notification, since Context Manager notifies whenever pedestrian status is changed.
 *			However, when LCD is off, notification occurs every 20 minutes with the log of pedestrian status changes.
 *			When there is no change in last 20 minutes, it contains one value, 0.
 *			Since pedestrian status is estimated in the unit of minutes, the array has at most 20 elements.
 */
extern const char CONTEXT_PEDOMETER_WALK_UP_STEP_COUNT_DIFF[];

/**
 * @brief	Walk down step count diff log data key of Integer array type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the log of walk down step count differences since the last notification.
 *			It has the size of #CONTEXT_PEDOMETER_LOG_COUNT.
 *
 *			When LCD is on, it contains only one diff value from last notification, since Context Manager notifies whenever pedestrian status is changed.
 *			However, when LCD is off, notification occurs every 20 minutes with the log of pedestrian status changes.
 *			When there is no change in last 20 minutes, it contains one value, 0.
 *			Since pedestrian status is estimated in the unit of minutes, the array has at most 20 elements.
 */
extern const char CONTEXT_PEDOMETER_WALK_DOWN_STEP_COUNT_DIFF[];

/**
 * @brief	Run (flat) step count diff log data key of Integer array type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the log of run (flat) step count differences since the last notification.
 *			It has the size of #CONTEXT_PEDOMETER_LOG_COUNT.
 *
 *			When LCD is on, it contains only one diff value from last notification, since Context Manager notifies whenever pedestrian status is changed.
 *			However, when LCD is off, notification occurs every 20 minutes with the log of pedestrian status changes.
 *			When there is no change in last 20 minutes, it contains one value, 0.
 *			Since pedestrian status is estimated in the unit of minutes, the array has at most 20 elements.
 */
extern const char CONTEXT_PEDOMETER_RUN_STEP_COUNT_DIFF[];

/**
 * @brief	Run up step count diff log data key of Integer array type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the log of run up step count differences since the last notification.
 *			It has the size of #CONTEXT_PEDOMETER_LOG_COUNT.
 *
 *			When LCD is on, it contains only one diff value from last notification, since Context Manager notifies whenever pedestrian status is changed.
 *			However, when LCD is off, notification occurs every 20 minutes with the log of pedestrian status changes.
 *			When there is no change in last 20 minutes, it contains one value, 0.
 *			Since pedestrian status is estimated in the unit of minutes, the array has at most 20 elements.
 */
extern const char CONTEXT_PEDOMETER_RUN_UP_STEP_COUNT_DIFF[];

/**
 * @brief	Run down step count diff log data key of Integer array type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the log of run down step count differences since the last notification.
 *			It has the size of #CONTEXT_PEDOMETER_LOG_COUNT.
 *
 *			When LCD is on, it contains only one diff value from last notification, since Context Manager notifies whenever pedestrian status is changed.
 *			However, when LCD is off, notification occurs every 20 minutes with the log of pedestrian status changes.
 *			When there is no change in last 20 minutes, it contains one value, 0.
 *			Since pedestrian status is estimated in the unit of minutes, the array has at most 20 elements.
 */
extern const char CONTEXT_PEDOMETER_RUN_DOWN_STEP_COUNT_DIFF[];

/**
 * @brief	Speed log data key of Double array type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value indicates the log of speed since the last notification.
 *			It has the size of #CONTEXT_PEDOMETER_LOG_COUNT.
 *
 *			When LCD is on, it contains only one current speed value, since Context Manager notifies whenever pedestrian status is changed.
 *			However, when LCD is off, notification occurs every 20 minutes with the log of pedestrian status changes.
 *			When there is no change in last 20 minutes, it contains one value, 0.0.
 *			Since pedestrian status is estimated in the unit of minutes, the array has at most 20 elements.
 */
extern const char CONTEXT_PEDOMETER_SPEED_LOG[];

/**
 * @brief	Pedometer mode key of Integer type for #CONTEXT_ITEM_PEDOMETER data.
 * @details	Its value will be one of #context_pedometer_mode.@n
 *			In case of #CONTEXT_PEDOMETER_MODE_LOGGING, the context data contains arrays of logged pedestrian data.
 *			Each element of an array indicates the sum (or average in case of #CONTEXT_PEDOMETER_SPEED_LOG) value in a minute,
 *			and the corresponding timestamp can be obtained by context_context_data_get_array_timestamp().@n
 *			The timestamp in the array denotes the nubmer of milliseconds that have elapsed since the last midnight, in UTC.
 */
extern const char CONTEXT_PEDOMETER_MODE[];

/**
 * @brief	SpO2 (%) data key for #CONTEXT_ITEM_HRM and #CONTEXT_ITEM_HRM_ALWAYS_ON data.
 *			The type is either Integer or integer array, regarding the related context item.
 * @details	Its value indicates the peripheral capillary oxygen saturation (SpO2).
 */
extern const char CONTEXT_HRM_SPO2[];

/**
 * @brief	Heart rate (Beats Per Minute) data key for #CONTEXT_ITEM_HRM and #CONTEXT_ITEM_HRM_ALWAYS_ON data.
 *			The type is either Integer or integer array, regarding the related context item.
 * @details	Its value indicates the heart rate. Exceptionally, -3 represents that the device is off the wrist.
 */
extern const char CONTEXT_HRM_HEART_RATE[];

/**
 * @brief	Peak-to-Peak interval (ms) data key for #CONTEXT_ITEM_HRM and #CONTEXT_ITEM_HRM_ALWAYS_ON data.
 *			The type is either Integer or integer array, regarding the related context item.
 * @details	Its value indicates the peak-to-peak interval of HRM sensor reading,
 *			which is known to closely resemble the RR interval measured from ECG.
 */
extern const char CONTEXT_HRM_PEAK_TO_PEAK[];

/**
 * @brief	SNR data key for #CONTEXT_ITEM_HRM and #CONTEXT_ITEM_HRM_ALWAYS_ON data.
 *			The type is either Double or double array, regarding the related context item.
 * @details	This value will be used during tuning process or when checking if the device is wrist-off.
 */
extern const char CONTEXT_HRM_SNR[];

/**
 * @brief	Step Length data key for #CONTEXT_ITEM_HRM and #CONTEXT_ITEM_HRM_ALWAYS_ON data.
 *			The type is either Integer or Integer array, regarding the related context item.
 * @details	This value is used to optimize the FB algorithm. It represents the step length difference in cm.
 *			If there is no difference, its value is 0. Its maximum value is 255.
 */
extern const char CONTEXT_HRM_STEP_LENGTH[];

/**
 * @brief	Deprecated.
 * @deprecated	Please use #CONTEXT_HRM_SPO2 instead.
 */
extern const char CONTEXT_HRM_EXT_SPO2[];
/**
 * @brief	Deprecated.
 * @deprecated	Please use #CONTEXT_HRM_HEART_RATE instead.
 */
extern const char CONTEXT_HRM_EXT_HEART_RATE[];
/**
 * @brief	Deprecated.
 * @deprecated	Please use #CONTEXT_HRM_PEAK_TO_PEAK instead.
 */
extern const char CONTEXT_HRM_EXT_PEAK_TO_PEAK[];
/**
 * @brief	Deprecated.
 * @deprecated	Please use #CONTEXT_HRM_SNR instead.
 */
extern const char CONTEXT_HRM_EXT_SNR[];

/**
 * @brief	Sleep status data array key of Integer array type for #CONTEXT_ITEM_SLEEP_MONITOR and #CONTEXT_ITEM_SLEEP_MONITOR_EXT data.
 * @details	Its value contains an integer array of sleep status.
 */
extern const char CONTEXT_SLEEP_MONITOR_STATUS[];

/**
 * @brief	PIM data array key of Double array type for #CONTEXT_ITEM_SLEEP_MONITOR_EXT data.
 * @details	The extra data is specific to Samsung's proprietary auto sleep duration detection algorithm.
 *			For more information, please refer to the algorithm.
 */
extern const char CONTEXT_SLEEP_MONITOR_PIM[];

/**
 * @brief	ZCM data array key of Integer array type for #CONTEXT_ITEM_SLEEP_MONITOR_EXT data.
 * @details	The extra data is specific to Samsung's proprietary auto sleep duration detection algorithm.
 *			For more information, please refer to the algorithm.
 */
extern const char CONTEXT_SLEEP_MONITOR_ZCM[];

/**
 * @brief	Stage data array key of Integer array type for #CONTEXT_ITEM_SLEEP_MONITOR_EXT data.
 * @details	The extra data is specific to Samsung's proprietary auto sleep duration detection algorithm.
 *			For more information, please refer to the algorithm.
 */
extern const char CONTEXT_SLEEP_MONITOR_STAGE[];

/**
 * @brief	Wrist data array key of Integer array type for #CONTEXT_ITEM_SLEEP_MONITOR_EXT data.
 * @details	The extra data is specific to Samsung's proprietary auto sleep duration detection algorithm.
 *			For more information, please refer to the algorithm.
 */
extern const char CONTEXT_SLEEP_MONITOR_WRIST[];

/**
 * @brief	Flag data array key of Integer array type for #CONTEXT_ITEM_SLEEP_MONITOR_EXT data.
 * @details	The extra data is specific to Samsung's proprietary auto sleep duration detection algorithm.
 *			For more information, please refer to the algorithm.
 */
extern const char CONTEXT_SLEEP_MONITOR_FLAG[];

/**
 * @brief	Activity status data key for #CONTEXT_ITEM_ACTIVITY_NOTIFICATION data. Integer.
 * @details	Its value indicates the activity status.
 * @see		context_activity_status
 */
extern const char CONTEXT_ACTIVITY_STATUS[];

/**
 * @brief	Activity accuracy data key for #CONTEXT_ITEM_ACTIVITY_NOTIFICATION data. Integer.
 * @details	Its value indicates the accuracy of the detected activity status.
 * @see		context_activity_accuracy
 */
extern const char CONTEXT_ACTIVITY_ACCURACY[];

/**
 * @}
 */

#endif // __TIZEN_SYSTEM_CONTEXT_MANAGER_TYPES_H__
