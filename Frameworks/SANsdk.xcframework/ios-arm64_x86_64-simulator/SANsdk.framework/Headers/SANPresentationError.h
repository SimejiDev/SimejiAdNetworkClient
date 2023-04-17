//
//  SANPresentError.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Error codes in the SAN Mobile Ads SDK domain that surface due to errors when attempting to
/// present an ad.
typedef NS_ENUM(NSInteger, SANPresentationErrorCode) {

  /// Ad isn't ready to be shown.
  SANPresentationErrorCodeAdNotReady = 15,

  /// Ad is too large for the scene.
  SANPresentationErrorCodeAdTooLarge = 16,

  /// Internal error.
  SANPresentationErrorCodeInternal = 17,

  /// Ad has already been used.
  SANPresentationErrorCodeAdAlreadyUsed = 18,

  /// Attempted to present ad from a non-main thread.
  SANPresentationErrorNotMainThread = 21,

  /// A mediation ad network adapter failed to present the ad. The adapter's error is included as an
  /// underlyingError.
  SANPresentationErrorMediation = 22,
};
