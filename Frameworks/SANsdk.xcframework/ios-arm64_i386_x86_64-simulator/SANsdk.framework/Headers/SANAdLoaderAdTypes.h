//
//  SANAdLoaderAdTypes.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SANMobileAdsDefines.h"

typedef NSString *SANAdLoaderAdType NS_STRING_ENUM;

/// Use with SANAdLoader to request native custom template ads. To receive ads, the ad loader's
/// delegate must conform to the SANCustomNativeAdLoaderDelegate protocol. See SANCustomNativeAd.h.
SAN_EXTERN SANAdLoaderAdType _Nonnull const kSANAdLoaderAdTypeCustomNative;

/// Use with SANAdLoader to request native ads. To receive ads, the ad loader's delegate must
/// conform to the SANNativeAdLoaderDelegate protocol. See SANNativeAd.h.
SAN_EXTERN SANAdLoaderAdType _Nonnull const kSANAdLoaderAdTypeNative;
