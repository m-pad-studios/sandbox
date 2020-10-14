import React from 'react'

import { css } from 'glamor'

class GalleryComments extends React.Component {

  render() {
    return (
      <div {...css(styles.title)}>
        <h1>Comments</h1>
        
      </div>
    )
  }
}

const styles = {
  title: {
    fontSize: 16,
    color: 'white'
  }
}

export default GalleryComments;