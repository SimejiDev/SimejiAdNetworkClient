//
//  SANRequestError.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SANMobileAdsDefines.h"

/// SAN Ads error domain.
SAN_EXTERN NSString *_Nonnull const SANErrorDomain;

/// NSError codes for SAN error domain.
typedef NS_ENUM(NSInteger, SANErrorCode) {
  /// The ad request is invalid. The localizedFailureReason error description will have more
  /// details. Typically this is because the ad did not have the ad unit ID or root view
  /// controller set.
  SANErrorInvalidRequest = 0,

  /// The ad request was successful, but no ad was returned.
  SANErrorNoFill = 1,

  /// There was an error loading data from the network.
  SANErrorNetworkError = 2,

  /// The ad server experienced a failure processing the request.
  SANErrorServerError = 3,

  /// The current device's OS is below the minimum required version.
  SANErrorOSVersionTooLow = 4,

  /// The request was unable to be loaded before being timed out.
  SANErrorTimeout = 5,

  /// The mediation response was invalid.
  SANErrorMediationDataError = 7,

  /// Error finding or creating a mediation ad network adapter.
  SANErrorMediationAdapterError = 8,

  /// Attempting to pass an invalid ad size to an adapter.
  SANErrorMediationInvalidAdSize = 10,

  /// Internal error.
  SANErrorInternalError = 11,

  /// Invalid argument error.
  SANErrorInvalidArgument = 12,

  /// Received invalid response.
  SANErrorReceivedInvalidResponse = 13,

  /// A mediation ad network adapter received an ad request, but did not fill. The adapter's error
  /// is included as an underlyingError.
  SANErrorMediationNoFill = 9,

  /// Will not send request because the ad object has already been used.
  SANErrorAdAlreadyUsed = 19,

  /// Will not send request because the application identifier is missing.
  SANErrorApplicationIdentifierMissing = 20,
};
