//
//  BCAProvider.m
//  Breadcrumb
//
//  Created by Andrew Hurst on 2/6/15.
//  Copyright (c) 2015 Breadcrumb. All rights reserved.
//

#import "BCAProvider.h"

@implementation BCAProvider

- (void)UTXOforAmount:(NSNumber *)amount
         andAddresses:(BCAddressManager *)addresses
         withCallback:(void (^)(NSArray *, NSError *))callback {
  NSAssert(FALSE, @"Called method on abstract class.");
}

- (void)publishTransaction:(BCMutableTransaction *)transaction
                   forCoin:(BCCoin *)coin
            withCompletion:(void (^)(NSError *))completion {
  NSAssert(FALSE, @"Called method on abstract class.");
}

@end
