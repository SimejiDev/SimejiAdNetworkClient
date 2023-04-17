//
//  SANCustomEventBannerDelegate.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SANMobileAdsDefines.h"

@protocol SANCustomEventBanner;

/// Call back to this delegate in your custom event. You must call customEventBanner:didReceiveAd:
/// when there is an ad to show, or customEventBanner:didFailAd: when there is no ad to show.
/// Otherwise, if enough time passed (several seconds) after the SDK called the requestBannerAd:
/// method of your custom event, the mediation SDK will consider the request timed out, and move on
/// to the next ad network.
@protocol SANCustomEventBannerDelegate <NSObject>

/// Your Custom Event object must call this when it receives or creates an ad view.
- (void)customEventBanner:(nonnull id<SANCustomEventBanner>)customEvent
             didReceiveAd:(nonnull UIView *)view;

/// Your Custom Event object must call this when it fails to receive or create the ad view. Pass
/// along any error object sent from the ad network's SDK, or an NSError describing the error. Pass
/// nil if not available.
- (void)customEventBanner:(nonnull id<SANCustomEventBanner>)customEvent
                didFailAd:(nullable NSError *)error;

/// Your Custom Event object should call this when the user touches or "clicks" the ad to initiate
/// an action. When the SDK receives this callback, it reports the click back to the mediation
/// server.
- (void)customEventBannerWasClicked:(nonnull id<SANCustomEventBanner>)customEvent;

/// The rootViewController that you set in SANBannerView. Use this UIViewController to show a modal
/// view when a user taps on the ad.
@property(nonatomic, readonly, nonnull) UIViewController *viewControllerForPresentingModalView;

/// When you call the following methods, the call will be propagated back to the
/// SANBannerViewDelegate that you implemented and passed to SANBannerView.

/// Your Custom Event should call this when the user taps an ad and a modal view appears.
- (void)customEventBannerWillPresentModal:(nonnull id<SANCustomEventBanner>)customEvent;

/// Your Custom Event should call this when the user dismisses the modal view and the modal view is
/// about to go away.
- (void)customEventBannerWillDismissModal:(nonnull id<SANCustomEventBanner>)customEvent;

/// Your Custom Event should call this when the user dismisses the modal view and the modal view has
/// gone away.
- (void)customEventBannerDidDismissModal:(nonnull id<SANCustomEventBanner>)customEvent;

#pragma mark Deprecated

/// Deprecated. Use customEventBannerWasClicked:.
- (void)customEventBanner:(nonnull id<SANCustomEventBanner>)customEvent
        clickDidOccurInAd:(nonnull UIView *)view
    SAN_DEPRECATED_MSG_ATTRIBUTE("Use customEventBannerWasClicked:.");

/// Deprecated. No replacment.
- (void)customEventBannerWillLeaveApplication:(nonnull id<SANCustomEventBanner>)customEvent
    SAN_DEPRECATED_ATTRIBUTE;

@end
