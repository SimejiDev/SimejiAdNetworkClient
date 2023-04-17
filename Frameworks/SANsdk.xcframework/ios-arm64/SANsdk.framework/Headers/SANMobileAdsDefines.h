//
//  SANMobileAdsDefines.h
//  SANsdk
//
//  Created by SAN on 2021/8/26.
//

#import <Foundation/Foundation.h>

#if defined(__cplusplus)
#define SAN_EXTERN extern "C" __attribute__((visibility("default")))
#else
#define SAN_EXTERN extern __attribute__((visibility("default")))
#endif  // defined(__cplusplus)

#if !defined(__has_feature)
#error "Use latest Xcode version."
#endif  // !defined(__has_feature)

#if !defined(__has_attribute)
#error "Use latest Xcode version."
#endif  // !defined(__has_attribute)

#if __has_feature(attribute_deprecated_with_message)
#define SAN_DEPRECATED_MSG_ATTRIBUTE(s) __attribute__((deprecated(s)))
#elif __has_attribute(deprecated)
#define SAN_DEPRECATED_MSG_ATTRIBUTE(s) __attribute__((deprecated))
#else
#define SAN_DEPRECATED_MSG_ATTRIBUTE(s)
#endif  // __has_feature(attribute_deprecated_with_message)

#if __has_attribute(deprecated)
#define SAN_DEPRECATED_ATTRIBUTE __attribute__((deprecated))
#else
#define SAN_DEPRECATED_ATTRIBUTE
#endif  // __has_attribute(deprecated)

#if __has_feature(nullability)  // Available starting in Xcode 6.3.
#define SAN_NULLABLE_TYPE __nullable
#define SAN_NONNULL_TYPE __nonnull
#define SAN_NULLABLE nullable
#else
#error "Use latest Xcode version."
#endif  // __has_feature(nullability)

#if __has_attribute(objc_boxable)  // Available starting in Xcode 7.3.
#define SAN_BOXABLE __attribute__((objc_boxable))
#else
#error "Use latest Xcode version."
#endif  // __has_attribute(objc_boxable)

#if defined(NS_STRING_ENUM)  // Available starting in Xcode 8.0.
#define SAN_STRING_ENUM NS_STRING_ENUM
#else
#error "Use latest Xcode version."
#endif

#define CAN_CALL(obj,method) ([obj respondsToSelector:@selector(method)])

