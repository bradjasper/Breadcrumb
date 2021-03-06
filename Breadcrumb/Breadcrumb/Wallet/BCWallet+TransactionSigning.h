//
//  BCWallet+TransactionSigning.h
//  Breadcrumb
//
//  Created by Andrew Hurst on 2/9/15.
//  Copyright (c) 2015 Breadcrumb.
//
//  Distributed under the MIT software license, see the accompanying
//  file LICENSE or http://www.opensource.org/licenses/mit-license.php.
//
//

#import "BCWallet.h"
#import "BCMutableTransaction.h"

@interface BCWallet (_TransactionSigning)

/*!
 @brief Signs the inputted transaction with this wallets keys.

 @param transaction The transaction to sign.
 @param key         The key to decrypt the wallets keys with.
 @param error       The location to put the signing error info if any.

 @return The signed transaction.
 */
- (BCMutableTransaction *)_signTransaction:(BCMutableTransaction *)transaction
                                   withKey:(NSData *)key
                                  andError:(NSError **)error;
@end

@interface BCWallet (_SecurityUtilities)

/*!
 @brief This generates a key using the wallet salt, and the given password.

 @discussion This method scrypt the inputted password with the salt from the
 wallets salt class method.

 This is a long running operation, and should not be executed on the main
 thread.

 @param password The password data to generate the key with.

 @return The 32 byte key, or NULL if the operation failed..
 */
+ (NSData *)_keyFromPassword:(NSData *)password;

/*!
 @brief The data that should be used as a salt on the current system.

 @discussion This is a per application/device salt based off of the applications
 container.

 This means that if the application is uninstalled, or the same application is
 installed on another device, and the keychain is shared across devices the
 other device won't be able to generate the key. This could be seen as a bug, or
 purposefully.

 If you want different behavior you should override this method in your
 subclass.
 */
+ (NSData *)_saltData;

@end
