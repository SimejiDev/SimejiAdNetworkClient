//
//  SANExtras.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SANAdNetworkExtras.h"

/// Ad network extras sent to SAN networks.
@interface SANExtras : NSObject <SANAdNetworkExtras>

/// Additional parameters to be sent to SAN networks.
@property(nonatomic, copy, nullable) NSDictionary *additionalParameters;

@end
