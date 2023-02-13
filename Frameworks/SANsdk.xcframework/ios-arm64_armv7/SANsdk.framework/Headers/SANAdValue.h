//
//  SANAdValue.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, SANAdValuePrecision) {
  /// An ad value with unknown precision.
  SANAdValuePrecisionUnknown = 0,
  /// An ad value estimated from aggregated data.
  SANAdValuePrecisionEstimated = 1,
  /// A publisher-provided ad value, such as manual CPMs in a mediation group.
  SANAdValuePrecisionPublisherProvided = 2,
  /// The precise value paid for this ad.
  SANAdValuePrecisionPrecise = 3
};

@class SANAdValue;

/// Handles ad events that are estimated to have earned money.
typedef void (^SANPaidEventHandler)(SANAdValue *_Nonnull value);

/// The monetary value earned from an ad.
@interface SANAdValue : NSObject <NSCopying>

/// The precision of the reported ad value.
@property(nonatomic, readonly) SANAdValuePrecision precision;

/// The ad's value.
@property(nonatomic, nonnull, readonly) NSDecimalNumber *value;

/// The value's currency code.
@property(nonatomic, nonnull, readonly) NSString *currencyCode;

@end
