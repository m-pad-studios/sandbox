import gql from 'graphql-tag';

export default gql`
mutation createManga(
    $name: String!,
    $contents: [String!],
    $texts: [String!]
){
    createManga(input: {
        name: $name, contents: $contents, texts: $texts,
    }) {
        id
        name
        contents
        texts
    }
}
`