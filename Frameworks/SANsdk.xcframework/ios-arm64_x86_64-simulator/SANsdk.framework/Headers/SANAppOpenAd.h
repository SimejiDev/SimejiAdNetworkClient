//
//  SANAppOpenAd.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SANAdValue.h"
#import "SANFullScreenContentDelegate.h"
#import "SANRequest.h"
#import "SANResponseInfo.h"

#pragma mark - App Open Ad

@class SANAppOpenAd;

/// The handler block to execute when the ad load operation completes. On failure, the
/// appOpenAd is nil and the |error| is non-nil. On success, the appOpenAd is non-nil and the
/// |error| is nil.
typedef void (^SANAppOpenAdLoadCompletionHandler)(SANAppOpenAd *_Nullable appOpenAd,
                                                  NSError *_Nullable error);

/// An app open ad. Used to monetize app load screens.
@interface SANAppOpenAd : NSObject <SANFullScreenPresentinSAN>

/// Loads an app open ad.
///
/// @param adUnitID An ad unit ID created in the Ad Manager UI.
/// @param request An ad request object. If nil, a default ad request object is used.
/// @param orientation The interface orientation that the ad will be presented in.
/// @param completionHandler A handler to execute when the load operation finishes or times out.
+ (void)loadWithAdUnitID:(nonnull NSString *)adUnitID
                 request:(nullable SANRequest *)request
             orientation:(UIInterfaceOrientation)orientation
       completionHandler:(nonnull SANAppOpenAdLoadCompletionHandler)completionHandler;

/// Optional delegate object that receives notifications about presentation and dismissal of full
/// screen content from this ad. Full screen content covers your application's content. The delegate
/// may want to pause animations and time sensitive interactions. Set this delegate before
/// presenting the ad.
@property(nonatomic, weak, nullable) id<SANFullScreenContentDelegate> fullScreenContentDelegate;

/// Information about the ad response that returned the ad.
@property(nonatomic, readonly, nonnull) SANResponseInfo *responseInfo;

/// Called when the ad is estimated to have earned money. Available for allowlisted accounts only.
@property(nonatomic, nullable, copy) SANPaidEventHandler paidEventHandler;

/// Returns whether the app open ad can be presented from the provided root view controller. Sets
/// the error out parameter if the app open ad can't be presented. Must be called on the main
/// thread.
- (BOOL)canPresentFromRootViewController:(nonnull UIViewController *)rootViewController
                                   error:(NSError *_Nullable __autoreleasing *_Nullable)error;

/// Presents the app open ad with the provided view controller. Must be called on the main thread.
- (void)presentFromRootViewController:(nonnull UIViewController *)rootViewController;

@end
