//
//  SANNativeAd.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SANAdChoicesView.h"
#import "SANAdLoaderDelegate.h"
#import "SANAdValue.h"
#import "SANMediaContent.h"
#import "SANMediaView.h"
#import "SANMuteThisAdReason.h"
#import "SANNativeAdAssetIdentifiers.h"
#import "SANNativeAdDelegate.h"
#import "SANNativeAdImage.h"
#import "SANResponseInfo.h"
#import "SANVideoController.h"

/// Native ad. To request this ad type, pass kSANAdLoaderAdTypeNative
/// (see SANAdLoaderAdTypes.h) to the |adTypes| parameter in SANAdLoader's initializer method. If
/// you request this ad type, your delegate must conform to the SANNativeAdLoaderDelegate
/// protocol.
@interface SANNativeAd : NSObject

#pragma mark - Must be displayed if available

/// Headline.
@property(nonatomic, readonly, copy, nullable) NSString *headline;

#pragma mark - Recommended to display

/// Text that encourages user to take some action with the ad. For example "Install".
@property(nonatomic, readonly, copy, nullable) NSString *callToAction;
/// Icon image.
@property(nonatomic, readonly, strong, nullable) SANNativeAdImage *icon;
/// The URL from which the icon image can be downloaded.
@property(nonatomic, readonly, copy, nullable) NSString *iconURL;
/// The scale of the image file (pixels/pts) that can be downloaded from iconURL.
@property(nonatomic, readonly, assign) CGFloat iconScale;
/// Description.
@property(nonatomic, readonly, copy, nullable) NSString *body;
/// Array of SANNativeAdImage objects.
@property(nonatomic, readonly, strong, nullable) NSArray<SANNativeAdImage *> *images;
/// The main image associated with the ad.
@property(nonatomic, readonly, strong, nullable) UIImage *image;
/// The URL from which the ad's main image can be downloaded.
@property(nonatomic, readonly, copy, nullable) NSString *imageURL;
/// The scale of the image file (pixels/pts) that can be downloaded from imageURL.
@property(nonatomic, readonly, assign) CGFloat imageScale;
/// App store rating (0 to 5).
@property(nonatomic, readonly, copy, nullable) NSDecimalNumber *starRating;
/// The app store name. For example, "App Store".
@property(nonatomic, readonly, copy, nullable) NSString *store;
/// String representation of the app's price.
@property(nonatomic, readonly, copy, nullable) NSString *price;
/// Identifies the advertiser. For example, the advertiser’s name or visible URL.
@property(nonatomic, readonly, copy, nullable) NSString *advertiser;
/// Media content. Set the associated media view's mediaContent property to this object to display
/// this content.
@property(nonatomic, readonly, nonnull) SANMediaContent *mediaContent;

#pragma mark - Other properties

/// Optional delegate to receive state change notifications.
@property(nonatomic, weak, nullable) id<SANNativeAdDelegate> delegate;

/// Reference to a root view controller that is used by the ad to present full screen content after
/// the user interacts with the ad. The root view controller is most commonly the view controller
/// displaying the ad.
@property(nonatomic, weak, nullable) UIViewController *rootViewController;

/// Dictionary of assets which aren't processed by the receiver.
@property(nonatomic, readonly, copy, nullable) NSDictionary<NSString *, id> *extraAssets;

/// Information about the ad response that returned the ad.
@property(nonatomic, readonly, nonnull) SANResponseInfo *responseInfo;

/// Called when the ad is estimated to have earned money. Available for allowlisted accounts only.
@property(nonatomic, nullable, copy) SANPaidEventHandler paidEventHandler;

/// Indicates whether custom Mute This Ad is available for the native ad.
@property(nonatomic, readonly, getter=isCustomMuteThisAdAvailable) BOOL customMuteThisAdAvailable;

/// An array of Mute This Ad reasons used to render customized mute ad survey. Use this array to
/// implement your own Mute This Ad feature only when customMuteThisAdAvailable is YES.
@property(nonatomic, readonly, nullable) NSArray<SANMuteThisAdReason *> *muteThisAdReasons;

/// Registers ad view, clickable asset views, and nonclickable asset views with this native ad.
/// Media view shouldn't be registered as clickable.
/// @param clickableAssetViews Dictionary of asset views that are clickable, keyed by asset IDs.
/// @param nonclickableAssetViews Dictionary of asset views that are not clickable, keyed by asset
///        IDs.
- (void)registerAdView:(nonnull UIView *)adView
       clickableAssetViews:
           (nonnull NSDictionary<SANNativeAssetIdentifier, UIView *> *)clickableAssetViews
    nonclickableAssetViews:
        (nonnull NSDictionary<SANNativeAssetIdentifier, UIView *> *)nonclickableAssetViews;

/// Unregisters ad view from this native ad. The corresponding asset views will also be
/// unregistered.
- (void)unregisterAdView;

/// Reports the mute event with the mute reason selected by user. Use nil if no reason was selected.
/// Call this method only if customMuteThisAdAvailable is YES.
- (void)muteThisAdWithReason:(nullable SANMuteThisAdReason *)reason;

/// Handles clicks on the native ad's assets (it just NSLogs them).
- (void)handleClickOnView:(UIView *_Nullable)view;

/// Records impressions for the native ad (it just NSLogs them).
- (void)recordImpression;

/// Starts playing the video after the view is rendered
- (void)playVideo;

- (void)fillMediaView:(nonnull SANMediaView *)mediaView;

@end

#pragma mark - Protocol and constants

/// The delegate of a SANAdLoader object implements this protocol to receive SANNativeAd ads.
@protocol SANNativeAdLoaderDelegate <SANAdLoaderDelegate>
/// Called when a native ad is received.
- (void)adLoader:(nonnull SANAdLoader *)adLoader didReceiveNativeAd:(nonnull SANNativeAd *)nativeAd;
@end

#pragma mark - Unified Native Ad View

/// Base class for native ad views. Your native ad view must be a subclass of this class and must
/// call superclass methods for all overridden methods.
@interface SANNativeAdView : UIView

/// This property must point to the native ad object rendered by this ad view.
@property(nonatomic, strong, nullable) SANNativeAd *nativeAd;

/// Weak reference to your ad view's headline asset view.
@property(nonatomic, weak, nullable) IBOutlet UIView *headlineView;
/// Weak reference to your ad view's call to action asset view.
@property(nonatomic, weak, nullable) IBOutlet UIView *callToActionView;
/// Weak reference to your ad view's icon asset view.
@property(nonatomic, weak, nullable) IBOutlet UIView *iconView;
/// Weak reference to your ad view's body asset view.
@property(nonatomic, weak, nullable) IBOutlet UIView *bodyView;
/// Weak reference to your ad view's store asset view.
@property(nonatomic, weak, nullable) IBOutlet UIView *storeView;
/// Weak reference to your ad view's price asset view.
@property(nonatomic, weak, nullable) IBOutlet UIView *priceView;
/// Weak reference to your ad view's image asset view.
@property(nonatomic, weak, nullable) IBOutlet UIView *imageView;
/// Weak reference to your ad view's star rating asset view.
@property(nonatomic, weak, nullable) IBOutlet UIView *starRatingView;
/// Weak reference to your ad view's advertiser asset view.
@property(nonatomic, weak, nullable) IBOutlet UIView *advertiserView;
/// Weak reference to your ad view's media asset view.
@property(nonatomic, weak, nullable) IBOutlet SANMediaView *mediaView;
/// Weak reference to your ad view's AdChoices view. Must set adChoicesView before setting
/// nativeAd, otherwise AdChoices will be rendered according to the preferredAdChoicesPosition
/// defined in SANNativeAdViewAdOptions.
@property(nonatomic, weak, nullable) IBOutlet SANAdChoicesView *adChoicesView;

@end
