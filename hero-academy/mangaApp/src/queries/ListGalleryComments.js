import gql from 'graphql-tag'

export default gql`
    query listComments {
        listMyCustomTypes {
            items {
                text
                id
                user
                created
            }
        }
    }
`