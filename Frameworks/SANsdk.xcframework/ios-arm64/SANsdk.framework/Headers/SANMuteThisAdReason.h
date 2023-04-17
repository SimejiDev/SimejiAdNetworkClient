//
//  SANMuteThisAdReason.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Reason for muting the ad.
@interface SANMuteThisAdReason : NSObject

/// Text that describes the reason for muting this ad. For example "Ad Covered Content".
@property(nonatomic, readonly, nonnull) NSString *reasonDescription;

@end
