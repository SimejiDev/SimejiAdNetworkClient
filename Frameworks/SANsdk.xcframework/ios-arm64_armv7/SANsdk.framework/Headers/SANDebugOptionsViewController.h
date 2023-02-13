//
//  SANDebugOptionsViewController.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class SANDebugOptionsViewController;

/// Delegate for the SANDebugOptionsViewController.
@protocol SANDebugOptionsViewControllerDelegate <NSObject>

/// Called when the debug options flow is finished.
- (void)debugOptionsViewControllerDidDismiss:(nonnull SANDebugOptionsViewController *)controller;

@end

/// Displays debug options to the user.
@interface SANDebugOptionsViewController : UIViewController

/// Creates and returns a SANDebugOptionsViewController object initialized with the ad unit ID.
/// @param adUnitID An ad unit ID for the SAN Ad Manager account that is being configured with
/// debug options.
+ (nonnull instancetype)debugOptionsViewControllerWithAdUnitID:(nonnull NSString *)adUnitID;

/// Delegate for the debug options view controller.
@property(nonatomic, weak, nullable) IBOutlet id<SANDebugOptionsViewControllerDelegate> delegate;

@end
