//
//  SANFullScreenContentDelegate.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SANFullScreenContentDelegate;

/// Protocol for ads that present full screen content.
@protocol SANFullScreenPresentinSAN <NSObject>

/// Delegate object that receives full screen content messages.
@property(nonatomic, weak, nullable) id<SANFullScreenContentDelegate> fullScreenContentDelegate;

@end

/// Delegate methods for receiving notifications about presentation and dismissal of full screen
/// content. Full screen content covers your application's content. The delegate may want to pause
/// animations or time sensitive interactions. Full screen content may be presented in the following
/// cases:
/// 1. A full screen ad is presented.
/// 2. An ad interaction opens full screen content.
@protocol SANFullScreenContentDelegate <NSObject>

@optional

/// Tells the delegate that an impression has been recorded for the ad.
- (void)adDidRecordImpression:(nonnull id<SANFullScreenPresentinSAN>)ad;

/// Tells the delegate that a click has been recorded for the ad.
- (void)adDidRecordClick:(nonnull id<SANFullScreenPresentinSAN>)ad;

/// Tells the delegate that the ad failed to present full screen content.
- (void)ad:(nonnull id<SANFullScreenPresentinSAN>)ad
    didFailToPresentFullScreenContentWithError:(nonnull NSError *)error;

/// Tells the delegate that the ad presented full screen content.
- (void)adDidPresentFullScreenContent:(nonnull id<SANFullScreenPresentinSAN>)ad;

/// Tells the delegate that the ad will dismiss full screen content.
- (void)adWillDismissFullScreenContent:(nonnull id<SANFullScreenPresentinSAN>)ad;

/// Tells the delegate that the ad dismissed full screen content.
- (void)adDidDismissFullScreenContent:(nonnull id<SANFullScreenPresentinSAN>)ad;

@end
