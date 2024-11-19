#ifdef __cplusplus
#import "react-native-unstoo-only-turbo.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNUnstooOnlyTurboSpec.h"

@interface UnstooOnlyTurbo : NSObject <NativeUnstooOnlyTurboSpec>
#else
#import <React/RCTBridgeModule.h>

@interface UnstooOnlyTurbo : NSObject <RCTBridgeModule>
#endif

@end
