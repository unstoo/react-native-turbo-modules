import React, {useState} from 'react';
import {StyleSheet, View, Button, ScrollView} from 'react-native';
import BcryptScreen from './src/Bcrypt/BcryptScreen';
import SimpleTurboScreen from './src/SimpleTurbo/SimpleTurboScreen';

export default function App() {
  const [screen, setScreen] = useState<string>('simpleTurbo');
  return (
    <View style={styles.container}>
      <ScrollView>
        {screen === 'simpleTurbo' && <SimpleTurboScreen />}
        {screen === 'bcrypt' && <BcryptScreen />}
      </ScrollView>
      <View style={styles.buttonContainer}>
        <Button
          title="Switch to Simple Turbo"
          onPress={() => setScreen('simpleTurbo')}
        />
        <Button title="Switch to Bcrypt" onPress={() => setScreen('bcrypt')} />
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    gap: 8,
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
  buttonContainer: {
    flexDirection: 'row',
    gap: 8,

    height: 60,
  },
});
