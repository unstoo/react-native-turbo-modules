import React from 'react';
import {SafeAreaView, StyleSheet, Text} from 'react-native';
import {multiply} from 'react-native-unstoo-only-turbo';



function App(): React.JSX.Element {
  React.useEffect(() => {
  }, []);
  return (
    <SafeAreaView style={styles.screen}>
      <Text>Turbo only 2x2={multiply(2, 2)}</Text>
      <Text>Native 2x2={4}</Text>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  screen: {
    flex: 1,
  },
});

export default App;
