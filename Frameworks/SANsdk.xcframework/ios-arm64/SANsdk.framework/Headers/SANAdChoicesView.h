//
//  SANAdChoicesView.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

/// Displays AdChoices content.
///
/// If a SANAdChoicesView is set on SANNativeAdView prior to calling -setNativeAd:, AdChoices
/// content will render inside the SANAdChoicesView. By default, AdChoices is placed in the top
/// right corner of SANNativeAdView.
@interface SANAdChoicesView : UIView
@end
