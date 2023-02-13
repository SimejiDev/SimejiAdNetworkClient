//
//  SANAdReward.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/// A block to be executed when the user earns a reward.
typedef void (^SANUserDidEarnRewardHandler)(void);

/// Ad reward information.
@interface SANAdReward : NSObject

/// Type of the reward.
@property(nonatomic, readonly, nonnull) NSString *type;

/// Amount rewarded to the user.
@property(nonatomic, readonly, nonnull) NSDecimalNumber *amount;

/// Returns an initialized SANAdReward with the provided reward type and reward amount.
- (nonnull instancetype)initWithRewardType:(nonnull NSString *)rewardType
                              rewardAmount:(nonnull NSDecimalNumber *)rewardAmount
    NS_DESIGNATED_INITIALIZER;

@end
