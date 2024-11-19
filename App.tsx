import React from 'react';
import {SafeAreaView, StyleSheet, Text} from 'react-native';

function App(): React.JSX.Element {
  return (
    <SafeAreaView style={styles.screen}>
      <Text>Hello</Text>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  screen: {
    flex: 1,
  },
});

export default App;
