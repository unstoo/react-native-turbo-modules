const UnstooBcrypt = require('./NativeUnstooBcrypt').default;

export function multiply(a: number, b: number): number {
  return UnstooBcrypt.multiply(a, b);
}
