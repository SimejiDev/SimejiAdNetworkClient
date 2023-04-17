//
//  SANCustomEventNativeAd.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SANCustomEventRequest.h"

@protocol SANCustomEventNativeAdDelegate;

/// Native ad custom event protocol. Your native ad custom event handler class must conform to this
/// protocol.
@protocol SANCustomEventNativeAd <NSObject>

/// Delegate object used for receiving custom native ad load request progress.
@property(nonatomic, weak, nullable) id<SANCustomEventNativeAdDelegate> delegate;

/// Returns an initialized custom event native ad.
- (nonnull instancetype)init;

/// Called when the custom event is scheduled to be executed.
///
/// @param serverParameter A value configured in the mediation UI for the custom event.
/// @param request Ad targeting information.
/// @param adTypes List of requested native ad types. See SANAdLoaderAdTypes.h for available ad
/// types.
/// @param options Additional options configured by the publisher for requesting a native ad. See
/// SANNativeAdImageAdLoaderOptions.h for available image options.
/// @param rootViewController Publisher-provided view controller.
- (void)requestNativeAdWithParameter:(nonnull NSString *)serverParameter
                             request:(nonnull SANCustomEventRequest *)request
                             adTypes:(nonnull NSArray *)adTypes
                             options:(nonnull NSArray *)options
                  rootViewController:(nonnull UIViewController *)rootViewController;

/// Indicates whether the custom event handles user clicks. Return YES if the custom event should
/// handle user clicks. In this case, the SAN Mobile Ads SDK doesn't track user clicks and the
/// custom event must notify the SAN Mobile Ads SDK of clicks using
/// +[SANMediatedNativeAdNotificationSource mediatedNativeAdDidRecordClick:]. Return NO if the
/// custom event doesn't handles user clicks. In this case, the SAN Mobile Ads SDK tracks user
/// clicks itself and the custom event is notified of user clicks via -[SANMediatedUnifiedNativeAd
/// didRecordClickOnAssetWithName:view:viewController:].
- (BOOL)handlesUserClicks;

/// Indicates whether the custom event handles user impressions tracking. If this method returns
/// YES, the SAN Mobile Ads SDK will not track user impressions and the custom event must notify
/// the SAN Mobile Ads SDK of impressions using +[SANMediatedNativeAdNotificationSource
/// mediatedNativeAdDidRecordImpression:]. If this method returns NO, the SAN Mobile Ads SDK
/// tracks user impressions and notifies the custom event of impressions using
/// -[SANMediatedUnifiedNativeAd didRecordImpression].
- (BOOL)handlesUserImpressions;

@end
