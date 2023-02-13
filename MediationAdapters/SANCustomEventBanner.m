//  SANCustomEventBanner.m
//  SANsdk
//
//  Created by SAN on 11/11/2021.
//  Copyright (c) 2021 SAN. All rights reserved.
//

#import "SANCustomEventBanner.h"

#import <Foundation/Foundation.h>
#import <SANsdk/SANMobileAds.h>

@interface SANCustomEventBanner () <SANBannerViewDelegate>

@property(nonatomic, strong) SANBannerView *bannerAd;

@end

@implementation SANCustomEventBanner

@synthesize delegate;

#pragma mark GADCustomEventBanner implementation

- (void)requestBannerAd:(GADAdSize)adSize
              parameter:(NSString *)serverParameter
                  label:(NSString *)serverLabel
                request:(GADCustomEventRequest *)request {
    // Create the bannerView with the appropriate size.
    SANAdSize size = SANAdSizeFromCGSize(adSize.size);
    self.bannerAd = [[SANBannerView alloc] initWithAdSize:size];
    
    self.bannerAd.delegate = self;
    self.bannerAd.adUnitID = serverParameter;
    SANRequest *adRequest = [SANRequest request];
    [self.bannerAd loadRequest:adRequest];
}

#pragma mark SANBannerViewDelegate implementation

- (void)bannerViewDidReceiveAd:(SANBannerView *)bannerView {
    [self.delegate customEventBanner:self didReceiveAd:bannerView];
}

- (void)bannerView:(SANBannerView *)bannerView didFailToReceiveAdWithError:(NSError *)error {
    [self.delegate customEventBanner:self didFailAd:error];
}

- (void)bannerViewDidRecordImpression:(SANBannerView *)bannerView {
    
}

- (void)bannerViewDidRecordClick:(SANBannerView *)bannerView {
    [self.delegate customEventBannerWasClicked:self];
}

- (void)bannerViewWillPresentScreen:(SANBannerView *)bannerView {
    [self.delegate customEventBannerWillPresentModal:self];
}

- (void)bannerViewWillDismissScreen:(SANBannerView *)bannerView {
    [self.delegate customEventBannerWillDismissModal:self];
}

- (void)bannerViewDidDismissScreen:(SANBannerView *)bannerView {
    [self.delegate customEventBannerDidDismissModal:self];
}

@end
