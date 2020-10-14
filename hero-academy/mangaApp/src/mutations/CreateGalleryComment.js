import gql from 'graphql-tag';

export default gql`
mutation createCustomTypes(
    $text: String!, $user: String!, $created: String!
){
    createMyCustomType(input: {
        text: $text, user: $user, created: $created
    }) {
        id
        text
        user
        created
    }
}
`