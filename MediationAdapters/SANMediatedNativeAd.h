//  SANMediatedNativeAd.h
//  SANsdk
//
//  Created by SAN on 11/11/2021.
//  Copyright (c) 2021 SAN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GoogleMobileAds/GoogleMobileAds.h>
#import <SANsdk/SANMobileAds.h>

@interface SANMediatedNativeAd : NSObject<GADMediatedUnifiedNativeAd>

- (null_unspecified instancetype)init NS_UNAVAILABLE;

- (nullable instancetype)initWithSANNativeAd:(nonnull SANNativeAd *)sanNativeAd
                       nativeAdViewAdOptions:(nullable GADNativeAdViewAdOptions *)nativeAdViewAdOptions NS_DESIGNATED_INITIALIZER;

- (void)loadImages;

@end
