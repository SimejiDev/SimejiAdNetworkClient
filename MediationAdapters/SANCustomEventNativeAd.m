//  SANCustomEventNativeAd.m
//  SANsdk
//
//  Created by SAN on 11/11/2021.
//  Copyright (c) 2021 SAN. All rights reserved.
//

#import "SANCustomEventNativeAd.h"
#import "SANMediatedNativeAd.h"

@interface SANCustomEventNativeAd () <SANNativeAdLoaderDelegate> {
    /// Native ad view options.
    GADNativeAdViewAdOptions *_nativeAdViewAdOptions;
}

@end

@implementation SANCustomEventNativeAd

@synthesize delegate;

- (void)requestNativeAdWithParameter:(NSString *)serverParameter
                             request:(GADCustomEventRequest *)request
                             adTypes:(NSArray *)adTypes
                             options:(NSArray *)options
                  rootViewController:(UIViewController *)rootViewController {
    
    SANVideoOptions *videoOptions = [[SANVideoOptions alloc] init];
    SANRequest *adRequest = [SANRequest request];
    SANAdLoader *adLoader = [[SANAdLoader alloc] initWithAdUnitID:serverParameter
                                               rootViewController:rootViewController
                                                          adTypes:@[ kSANAdLoaderAdTypeNative ]
                                                          options:@[ videoOptions ]];
    adLoader.delegate = self;
    [adLoader loadRequest:adRequest];
    
    for (GADAdLoaderOptions *loaderOptions in options) {
        if ([loaderOptions isKindOfClass:[GADNativeAdImageAdLoaderOptions class]]) {
            // GADNativeAdImageAdLoaderOptions *imageOptions = (GADNativeAdImageAdLoaderOptions *)loaderOptions;
        } else if ([loaderOptions isKindOfClass:[GADNativeAdMediaAdLoaderOptions class]]) {
            // GADNativeAdMediaAdLoaderOptions *mediaOptions = (GADNativeAdMediaAdLoaderOptions *)loaderOptions;
        } else if ([loaderOptions isKindOfClass:[GADNativeAdViewAdOptions class]]) {
            _nativeAdViewAdOptions = (GADNativeAdViewAdOptions *)loaderOptions;
        }
    }
}

// Indicates if the custom event handles user clicks. Return YES if the custom event should handle
// user clicks.
- (BOOL)handlesUserClicks {
    return NO;
}

- (BOOL)handlesUserImpressions {
    return NO;
}

#pragma mark SANNativeAdLoaderDelegate implementation

- (void)adLoader:(SANAdLoader *)adLoader didReceiveNativeAd:(SANNativeAd *)nativeAd {
    SANMediatedNativeAd *mediatedAd = [[SANMediatedNativeAd alloc] initWithSANNativeAd:nativeAd nativeAdViewAdOptions:_nativeAdViewAdOptions];
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        [mediatedAd loadImages];
        dispatch_async(dispatch_get_main_queue(), ^(void) {
            [self.delegate customEventNativeAd:self didReceiveMediatedUnifiedNativeAd:mediatedAd];
        });
    });
}

- (void)adLoader:(SANAdLoader *)adLoader didFailToReceiveAdWithError:(NSError *)error {
    [self.delegate customEventNativeAd:self didFailToLoadWithError:error];
}

@end
