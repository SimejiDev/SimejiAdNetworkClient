//
//  SANAdNetworkExtras.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/// An object implementing this protocol contains information set by the publisher on the client
/// device for a particular ad network.
///
/// Ad networks should create an 'extras' object implementing this protocol for their publishers to
/// use.
@protocol SANAdNetworkExtras <NSObject>
@end
