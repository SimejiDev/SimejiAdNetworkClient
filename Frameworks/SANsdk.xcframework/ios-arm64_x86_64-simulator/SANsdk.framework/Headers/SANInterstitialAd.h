//
//  SANInterstitialAd.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SANAdValue.h"
#import "SANFullScreenContentDelegate.h"
#import "SANRequest.h"
#import "SANResponseInfo.h"
#import "SANServerSideVerificationOptions.h"

@class SANInterstitialAd;

/// A block to be executed when the ad request operation completes. On success,
/// interstitialAd is non-nil and |error| is nil. On failure, interstitialAd is nil
/// and |error| is non-nil.
typedef void (^SANInterstitialAdLoadCompletionHandler)(SANInterstitialAd *_Nullable interstitialAd,
                                                       NSError *_Nullable error);

/// An interstitial ad. This is a full-screen advertisement shown at natural transition points in
/// your application such as between game levels or news stories.
@interface SANInterstitialAd : NSObject <SANFullScreenPresentinSAN>

/// The ad unit ID.
@property(nonatomic, readonly, nonnull) NSString *adUnitID;

/// Information about the ad response that returned the ad.
@property(nonatomic, readonly, nonnull) SANResponseInfo *responseInfo;

/// Delegate for handling full screen content messages.
@property(nonatomic, weak, nullable) id<SANFullScreenContentDelegate> fullScreenContentDelegate;

/// Called when the ad is estimated to have earned money. Available for allowlisted accounts only.
@property(nonatomic, nullable, copy) SANPaidEventHandler paidEventHandler;

/// Loads an interstitial ad.
///
/// @param adUnitID An ad unit ID created in the Ad Manager UI.
/// @param request An ad request object. If nil, a default ad request object is used.
/// @param completionHandler A handler to execute when the load operation finishes or times out.
+ (void)loadWithAdUnitID:(nonnull NSString *)adUnitID
                 request:(nullable SANRequest *)request
       completionHandler:(nonnull SANInterstitialAdLoadCompletionHandler)completionHandler;

/// Returns whether the interstitial ad can be presented from the provided root view
/// controller. Sets the error out parameter if the ad can't be presented. Must be called on the
/// main thread.
- (BOOL)canPresentFromRootViewController:(nonnull UIViewController *)rootViewController
                                   error:(NSError *_Nullable __autoreleasing *_Nullable)error;

/// Presents the interstitial ad. Must be called on the main thread.
///
/// @param rootViewController A view controller to present the ad.
- (void)presentFromRootViewController:(nonnull UIViewController *)rootViewController;

@end
