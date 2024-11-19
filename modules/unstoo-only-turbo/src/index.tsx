const UnstooOnlyTurbo = require('./NativeUnstooOnlyTurbo').default;

export function multiply(a: number, b: number): number {
  return UnstooOnlyTurbo.multiply(a, b);
}
