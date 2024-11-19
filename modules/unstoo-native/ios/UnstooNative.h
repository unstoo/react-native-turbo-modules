#ifdef __cplusplus
#import "react-native-unstoo-native.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNUnstooNativeSpec.h"

@interface UnstooNative : NSObject <NativeUnstooNativeSpec>
#else
#import <React/RCTBridgeModule.h>

@interface UnstooNative : NSObject <RCTBridgeModule>
#endif

@end
