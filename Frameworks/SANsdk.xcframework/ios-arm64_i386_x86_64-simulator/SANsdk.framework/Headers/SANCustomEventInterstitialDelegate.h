//
//  SANCustomEventInterstitialDelegate.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SANMobileAdsDefines.h"

@protocol SANCustomEventInterstitial;

/// Call back to this delegate in your custom event. You must call
/// customEventInterstitialDidReceiveAd: when there is an ad to show, or
/// customEventInterstitial:didFailAd: when there is no ad to show. Otherwise, if enough time passed
/// (several seconds) after the SDK called the requestInterstitialAdWithParameter: method of your
/// custom event, the mediation SDK will consider the request timed out, and move on to the next ad
/// network.
@protocol SANCustomEventInterstitialDelegate <NSObject>

/// Your Custom Event object must call this when it receives or creates an interstitial ad.
- (void)customEventInterstitialDidReceiveAd:(nonnull id<SANCustomEventInterstitial>)customEvent;

/// Your Custom Event object must call this when it fails to receive or create the ad. Pass along
/// any error object sent from the ad network's SDK, or an NSError describing the error. Pass nil if
/// not available.
- (void)customEventInterstitial:(nonnull id<SANCustomEventInterstitial>)customEvent
                      didFailAd:(nullable NSError *)error;

/// Your Custom Event object should call this when the user touches or "clicks" the ad to initiate
/// an action. When the SDK receives this callback, it reports the click back to the mediation
/// server.
- (void)customEventInterstitialWasClicked:(nonnull id<SANCustomEventInterstitial>)customEvent;

// When you call any of the following methods, the call will be propagated back to the
// SANInterstitialDelegate that you implemented and passed to SANInterstitial.

/// Your Custom Event should call this when the interstitial is being displayed.
- (void)customEventInterstitialWillPresent:(nonnull id<SANCustomEventInterstitial>)customEvent;

/// Your Custom Event should call this when the interstitial is about to be dismissed.
- (void)customEventInterstitialWillDismiss:(nonnull id<SANCustomEventInterstitial>)customEvent;

/// Your Custom Event should call this when the interstitial has been dismissed.
- (void)customEventInterstitialDidDismiss:(nonnull id<SANCustomEventInterstitial>)customEvent;

#pragma mark Deprecated

/// Deprecated. Use customEventInterstitialDidReceiveAd:.
- (void)customEventInterstitial:(nonnull id<SANCustomEventInterstitial>)customEvent
                   didReceiveAd:(nonnull NSObject *)ad
    SAN_DEPRECATED_MSG_ATTRIBUTE("Use customEventInterstitialDidReceiveAd:.");

/// Deprecated. No replacement.
- (void)customEventInterstitialWillLeaveApplication:
    (nonnull id<SANCustomEventInterstitial>)customEvent SAN_DEPRECATED_ATTRIBUTE;

@end
