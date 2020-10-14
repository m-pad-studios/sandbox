import gql from 'graphql-tag';

export default gql`
    subscription NewMangaSub {
        onCreateManga {
            name
            id
            contents
            texts
        }
    }
`