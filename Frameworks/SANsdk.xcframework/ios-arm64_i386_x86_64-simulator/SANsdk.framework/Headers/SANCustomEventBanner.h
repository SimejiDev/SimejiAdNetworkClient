//
//  SANCustomEventBanner.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SANAdSize.h"
#import "SANCustomEventBannerDelegate.h"
#import "SANCustomEventRequest.h"

/// The banner custom event protocol. Your banner custom event handler must implement this protocol.
@protocol SANCustomEventBanner <NSObject>

/// Inform |delegate| with the custom event execution results to ensure mediation behaves correctly.
///
/// In your class, define the -delegate and -setDelegate: methods or use "@synthesize delegate". The
/// SAN Mobile Ads SDK sets this property on instances of your class.
@property(nonatomic, weak, nullable) id<SANCustomEventBannerDelegate> delegate;

/// Returns an initialized custom event banner.
- (nonnull instancetype)init;

/// Called by mediation when your custom event is scheduled to be executed. Report execution results
/// to the delegate.
///
/// @param adSize The size of the ad as configured in the mediation UI for the mediation placement.
/// @param serverParameter Parameter configured in the mediation UI.
/// @param serverLabel Label configured in the mediation UI.
/// @param request Contains ad request information.
- (void)requestBannerAd:(SANAdSize)adSize
              parameter:(nullable NSString *)serverParameter
                  label:(nullable NSString *)serverLabel
                request:(nonnull SANCustomEventRequest *)request;

@end
