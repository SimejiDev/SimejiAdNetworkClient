//
//  SANCustomNativeAd.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SANAdLoaderDelegate.h"
#import "SANDisplayAdMeasurement.h"
#import "SANMediaView.h"
#import "SANNativeAdImage.h"
#import "SANResponseInfo.h"
#import "SANVideoController.h"

/// Native ad custom click handler block. |assetID| is the ID of asset that has received a click.
typedef void (^SANNativeAdCustomClickHandler)(NSString *_Nonnull assetID);

/// Asset key for the SANMediaView asset view.
SAN_EXTERN NSString *_Nonnull const SANCustomNativeAdMediaViewKey;

@protocol SANCustomNativeAdDelegate;

/// Custom native ad. To request this ad type, you need to pass
/// kSANAdLoaderAdTypeCustomNative (see SANAdLoaderAdTypes.h) to the |adTypes| parameter
/// in SANAdLoader's initializer method. If you request this ad type, your delegate must conform to
/// the SANCustomNativeAdLoaderDelegate protocol.
@interface SANCustomNativeAd : NSObject

/// The ad's format ID.
@property(nonatomic, readonly, nonnull) NSString *formatID;

/// Array of available asset keys.
@property(nonatomic, readonly, nonnull) NSArray<NSString *> *availableAssetKeys;

/// Custom click handler. Set this property only if this ad is configured with a custom click
/// action, otherwise set it to nil. If this property is set to a non-nil value, the ad's built-in
/// click actions are ignored and |customClickHandler| is executed when a click on the asset is
/// received.
@property(atomic, copy, nullable) SANNativeAdCustomClickHandler customClickHandler;

/// The display ad measurement associated with this ad.
@property(nonatomic, readonly, nullable) SANDisplayAdMeasurement *displayAdMeasurement;

/// Media content.
@property(nonatomic, readonly, nonnull) SANMediaContent *mediaContent;

/// Optional delegate to receive state change notifications.
@property(nonatomic, weak, nullable) id<SANCustomNativeAdDelegate> delegate;

/// Reference to a root view controller that is used by the ad to present full screen content after
/// the user interacts with the ad. The root view controller is most commonly the view controller
/// displaying the ad.
@property(nonatomic, weak, nullable) UIViewController *rootViewController;

/// Information about the ad response that returned the ad.
@property(nonatomic, readonly, nonnull) SANResponseInfo *responseInfo;

/// Returns the native ad image corresponding to the specified key or nil if the image is not
/// available.
- (nullable SANNativeAdImage *)imageForKey:(nonnull NSString *)key;

/// Returns the string corresponding to the specified key or nil if the string is not available.
- (nullable NSString *)stringForKey:(nonnull NSString *)key;

/// Call when the user clicks on the ad. Provide the asset key that best matches the asset the user
/// interacted with. If this ad is configured with a custom click action, ensure the receiver's
/// customClickHandler property is set before calling this method.
- (void)performClickOnAssetWithKey:(nonnull NSString *)assetKey;

/// Call when the ad is displayed on screen to the user. Can be called multiple times. Only the
/// first impression is recorded.
- (void)recordImpression;

/// Returns media view for rendering video loaded by the receiver. Returns nil if receiver doesn't
/// have a video.
@property(nonatomic, readonly, nullable) SANMediaView *mediaView SAN_DEPRECATED_MSG_ATTRIBUTE(
    "Use the mediaContent property to set the media content on your own SANMediaView.");

@end

#pragma mark - Loading Protocol

/// The delegate of a SANAdLoader object implements this protocol to receive
/// SANCustomNativeAd ads.
@protocol SANCustomNativeAdLoaderDelegate <SANAdLoaderDelegate>

/// Called when requesting an ad. Asks the delegate for an array of custom native ad format ID
/// strings.
- (nonnull NSArray<NSString *> *)customNativeAdFormatIDsForAdLoader:(nonnull SANAdLoader *)adLoader;

/// Tells the delegate that a custom native ad was received.
- (void)adLoader:(nonnull SANAdLoader *)adLoader
    didReceiveCustomNativeAd:(nonnull SANCustomNativeAd *)customNativeAd;

@end
