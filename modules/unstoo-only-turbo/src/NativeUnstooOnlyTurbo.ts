import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  reverseString(input: string): string;

  getNumbers(): number[];

  getObject(): { [key: string]: string };

  promiseNumber(value: number): Promise<number>;

  callbacks(success: (value?: string) => void, failure: (error?: string) => void): void;
}

export default TurboModuleRegistry.getEnforcing<Spec>('UnstooOnlyTurbo');
