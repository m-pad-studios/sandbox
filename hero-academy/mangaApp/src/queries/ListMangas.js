import gql from 'graphql-tag';

export default gql`
    query listMangas {
        listMangas {
            items {
            name
            id
            contents
            texts
            }
        }
    }
`