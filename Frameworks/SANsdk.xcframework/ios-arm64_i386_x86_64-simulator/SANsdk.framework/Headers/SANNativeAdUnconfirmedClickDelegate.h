//
//  SANNativeAdUnconfirmedClickDelegate.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SANNativeAdAssetIdentifiers.h"

@class SANNativeAd;

/// Delegate methods for handling native ad unconfirmed clicks.
@protocol SANNativeAdUnconfirmedClickDelegate <NSObject>

/// Tells the delegate that native ad receives an unconfirmed click on view with asset ID. You
/// should update user interface and ask user to confirm the click once this message is received.
/// Use the -registerClickConfirmingView: method in SANNativeAd+ConfirmedClick.h to register
/// a view that will confirm the click. Only called for SAN ads and is not supported for mediated
/// ads.
- (void)nativeAd:(nonnull SANNativeAd *)nativeAd
    didReceiveUnconfirmedClickOnAssetID:(nonnull SANNativeAssetIdentifier)assetID;

/// Tells the delegate that the unconfirmed click is cancelled. You should revert the user interface
/// change once this message is received. Only called for SAN ads and is not supported for
/// mediated ads.
- (void)nativeAdDidCancelUnconfirmedClick:(nonnull SANNativeAd *)nativeAd;

@end
