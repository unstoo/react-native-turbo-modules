#ifdef __cplusplus
#import "react-native-unstoo-turbo.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNUnstooTurboSpec.h"

@interface UnstooTurbo : NSObject <NativeUnstooTurboSpec>
#else
#import <React/RCTBridgeModule.h>

@interface UnstooTurbo : NSObject <RCTBridgeModule>
#endif

@end
