//
//  BCProviderChain.h
//  Breadcrumb
//
//  Created by Andrew Hurst on 2/6/15.
//  Copyright (c) 2015 Breadcrumb.
//
//  Distributed under the MIT software license, see the accompanying
//  file LICENSE or http://www.opensource.org/licenses/mit-license.php.
//
//

#import "BCAProvider.h"

/*!
 @brief A sample provider using the Chain API with a local cache, that publishes
 transactions to the bitcoin network.
 */
@interface BCProviderChain : BCAProvider

@end

@interface BCTransaction (BCProviderChain)
/*!
 @brief Instantiates the transaction from transaction data formatted in a Chain
 response.

 @param chainTransaction The chain response to build the transaction with.
 */
+ (instancetype)transactionFromChainTransaction:
        (NSDictionary *)chainTransaction;
@end
