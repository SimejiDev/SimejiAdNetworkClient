//
//  SANAdFormat.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Requested ad format.
typedef NS_ENUM(NSInteger, SANAdFormat) {
  SANAdFormatBanner,                ///< Banner.
  SANAdFormatInterstitial,          ///< Interstitial.
  SANAdFormatRewarded,              ///< Rewarded.
  SANAdFormatNative,                ///< Native.
  SANAdFormatRewardedInterstitial,  ///< Rewarded interstitial.
  SANAdFormatUnknown,               ///< Unknown.
};
