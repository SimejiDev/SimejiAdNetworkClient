//
//  SANCustomEventInterstitial.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SANCustomEventInterstitialDelegate.h"
#import "SANCustomEventRequest.h"

/// The interstitial custom event protocol. Your interstitial custom event handler must implement
/// this protocol.
@protocol SANCustomEventInterstitial <NSObject>

/// Inform |delegate| with the custom event execution results to ensure mediation behaves correctly.
///
/// In your class, define the -delegate and -setDelegate: methods or use "@synthesize delegate". The
/// SAN Mobile Ads SDK sets this property on instances of your class.
@property(nonatomic, weak, nullable) id<SANCustomEventInterstitialDelegate> delegate;

/// Returns an initialized custom event interstitial.
- (nonnull instancetype)init;

/// Called by mediation when your custom event is scheduled to be executed. Your implementation
/// should start retrieving the interstitial ad. Report execution results to the delegate. You must
/// wait until -presentFromRootViewController is called before displaying the interstitial ad.
///
/// @param serverParameter Parameter configured in the mediation UI.
/// @param serverLabel Label configured in the mediation UI.
/// @param request Contains ad request information.
- (void)requestInterstitialAdWithParameter:(nullable NSString *)serverParameter
                                     label:(nullable NSString *)serverLabel
                                   request:(nonnull SANCustomEventRequest *)request;

/// Present the interstitial ad as a modal view using the provided view controller. Called only
/// after your class calls -customEventInterstitialDidReceiveAd: on its custom event delegate.
- (void)presentFromRootViewController:(nonnull UIViewController *)rootViewController;

@end
