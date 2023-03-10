//
//  SANNativeAd+ConfirmationClick.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SANNativeAd.h"
#import "SANNativeAdUnconfirmedClickDelegate.h"

@interface SANNativeAd (ConfirmedClick)

/// Unconfirmed click delegate.
@property(nonatomic, weak, nullable) id<SANNativeAdUnconfirmedClickDelegate>
    unconfirmedClickDelegate;

/// Registers a view that will confirm the click.
- (void)registerClickConfirmingView:(nullable UIView *)view;

/// Cancels the unconfirmed click. Call this method when the user fails to confirm the click.
/// Calling this method causes the SDK to stop tracking clicks on the registered click confirming
/// view and invokes the -nativeAdDidCancelUnconfirmedClick: delegate method. If no unconfirmed
/// click is in progress, this method has no effect.
- (void)cancelUnconfirmedClick;

@end
