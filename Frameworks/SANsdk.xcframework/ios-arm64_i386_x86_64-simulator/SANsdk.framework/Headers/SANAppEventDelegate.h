//
//  SANAppEventDelegate.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SANBannerView;
@class SANInterstitialAd;

/// Implement your app event within these methods. The delegate will be notified when the SDK
/// receives an app event message from the ad.
@protocol SANAppEventDelegate <NSObject>

@optional

/// Called when the banner receives an app event.
- (void)adView:(nonnull SANBannerView *)banner
    didReceiveAppEvent:(nonnull NSString *)name
              withInfo:(nullable NSString *)info;

/// Called when the interstitial receives an app event.
- (void)interstitialAd:(nonnull SANInterstitialAd *)interstitialAd
    didReceiveAppEvent:(nonnull NSString *)name
              withInfo:(nullable NSString *)info;

@end
