import gql from 'graphql-tag'

export default gql`
    subscription NewMyCustomTypeSub {
        onCreateMyCustomType {
            id
            text
            user
            created
        }
    }
`