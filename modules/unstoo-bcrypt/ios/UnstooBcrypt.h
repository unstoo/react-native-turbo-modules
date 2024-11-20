#ifdef __cplusplus
#import "react-native-unstoo-bcrypt.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNUnstooBcryptSpec.h"

@interface UnstooBcrypt : NSObject <NativeUnstooBcryptSpec>
#else
#import <React/RCTBridgeModule.h>

@interface UnstooBcrypt : NSObject <RCTBridgeModule>
#endif

@end
