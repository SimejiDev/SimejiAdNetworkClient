//
//  SANMobileAds.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SANAdLoader.h"
#import "SANAdLoaderAdTypes.h"
#import "SANNativeAd.h"
#import "SANNativeAdViewAdOptions.h"
#import "SANNativeAdImageAdLoaderOptions.h"
#import "SANNativeAdMediaAdLoaderOptions.h"
#import "SANBannerView.h"

#import "SANAudioVideoManager.h"
#import "SANInitializationStatus.h"
#import "SANRequestConfiguration.h"
#import "SANVideoControllerDelegate.h"
#import "SANVideoOptions.h"

#import "SANExtras.h"

/// A block called with the initialization status when [SANMobileAds startWithCompletionHandler:]
/// completes or times out.
typedef void (^SANInitializationCompletionHandler)(SANInitializationStatus *_Nonnull status);

/// Completion handler for presenting Ad Inspector. Returns an error if a problem was detected
/// during presentation, or nil otherwise.
typedef void (^SANAdInspectorCompletionHandler)(NSError *_Nullable error);

/// SAN Mobile Ads SDK settings.
@interface SANMobileAds : NSObject

/// Returns the shared SANMobileAds instance.
+ (nonnull SANMobileAds *)sharedInstance;

/// Returns the version of the SDK.
@property(nonatomic, nonnull, readonly) NSString *sdkVersion;

@property(nonatomic, assign) BOOL isDebug;

/// The application's audio volume. Affects audio volumes of all ads relative to other audio output.
/// Valid ad volume values range from 0.0 (silent) to 1.0 (current device volume). Use this method
/// only if your application has its own volume controls (e.g., custom music or sound effect
/// volumes). Defaults to 1.0.
@property(nonatomic, assign) float applicationVolume;

/// Indicates whether the application's audio is muted. Affects initial mute state for all ads. Use
/// this method only if your application has its own volume controls (e.g., custom music or sound
/// effect muting). Defaults to NO.
@property(nonatomic, assign) BOOL applicationMuted;

/// Manages the SAN Mobile Ads SDK's audio and video settings.
@property(nonatomic, readonly, strong, nonnull) SANAudioVideoManager *audioVideoManager;

/// Request configuration that is common to all requests.
@property(nonatomic, readonly, strong, nonnull) SANRequestConfiguration *requestConfiguration;

/// Initialization status of the ad networks available to the SAN Mobile Ads SDK.
@property(nonatomic, nonnull, readonly) SANInitializationStatus *initializationStatus;

/// Returns YES if the current SDK version is at least |major|.|minor|.|patch|. This method can be
/// used by libraries that depend on a specific minimum version of the SAN Mobile Ads SDK to warn
/// developers if they have an incompatible version.
///
/// Available in SAN Mobile Ads SDK 7.10 and onwards. Before calling this method check if the
/// SANMobileAds's shared instance responds to this method. Calling this method on a SAN Mobile
/// Ads SDK lower than 7.10 can crash the app.
- (BOOL)isSDKVersionAtLeastMajor:(NSInteger)major minor:(NSInteger)minor patch:(NSInteger)patch;

/// Starts the SAN Mobile Ads SDK. Call this method as early as possible to reduce latency on the
/// session's first ad request. Calls completionHandler when the GMA SDK and all mediation networks
/// are fully set up or if set-up times out. The SAN Mobile Ads SDK starts on the first ad
/// request if this method is not called.
- (void)startWithCompletionHandler:(nullable SANInitializationCompletionHandler)completionHandler;

/// Disables automated SDK crash reporting. If not called, the SDK records the original exception
/// handler if available and registers a new exception handler. The new exception handler only
/// reports SDK related exceptions and calls the recorded original exception handler.
- (void)disableSDKCrashReporting;

/// Disables mediation adapter initialization during initialization of the GMA SDK. Calling this
/// method may negatively impact your ad performance and should only be called if you will not use
/// GMA SDK controlled mediation during this app session. This method must be called before
/// initializing the GMA SDK or loading ads and has no effect once the SDK has been initialized.
- (void)disableMediationInitialization;

/// Presents Ad Inspector. The device calling this API must be registered as a test device in order
/// to launch Ad Inspector. Set
/// SANMobileAds.sharedInstance.requestConfiguration.testDeviceIdentifiers to enable test mode on
/// this device.
/// @param viewController A view controller to present Ad Inspector.
/// @param completionHandler A handler to execute when Ad Inspector is closed.
- (void)presentAdInspectorFromViewController:(nonnull UIViewController *)viewController
                           completionHandler:
                               (nullable SANAdInspectorCompletionHandler)completionHandler;

#pragma mark Deprecated

/// Deprecated and does nothing. IAP transaction reporting is no longer supported.
- (void)disableAutomatedInAppPurchaseReporting SAN_DEPRECATED_ATTRIBUTE;

/// Deprecated and does nothing. IAP transaction reporting is no longer supported.
- (void)enableAutomatedInAppPurchaseReporting SAN_DEPRECATED_ATTRIBUTE;

@end
