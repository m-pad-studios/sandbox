import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import AppWithAuth from './components/AppWithAuth';
import AWSAppSyncClient, { AUTH_TYPE } from "aws-appsync";
import { Rehydrated } from 'aws-appsync-react';
import { ApolloProvider } from 'react-apollo';
import appSyncConfig from './appsync';
import Amplify from 'aws-amplify';
import awsconfig from './aws-exports';

Amplify.configure(awsconfig);

const client = new AWSAppSyncClient({

  url: appSyncConfig.aws_appsync_graphqlEndpoint,
  region: appSyncConfig.aws_appsync_region,
  auth: {
      type: AUTH_TYPE.API_KEY,
      apiKey: appSyncConfig.aws_appsync_apiKey,
  }
});

const WithProvider = () => (

  <ApolloProvider client={client}>
  <Rehydrated render={({ rehydrated }) => (
    rehydrated ? <AppWithAuth /> : <h1>Not loading</h1>
  )} />
</ApolloProvider>

);

ReactDOM.render(
  <WithProvider />,
  document.getElementById('root')
);