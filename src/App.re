type state = {count: int};

type action =
  | Increment
  | Decrement;

let initialState = {count: 0};

let reducer = (state, action) =>
  switch (action) {
  | Increment => {count: state.count + 1}
  | Decrement => {count: state.count - 1}
  };

[@react.component]
let make = (~userName) => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  
  /*
   * Create a style. Hyphenated CSS property names like margin-left become marginLeft.
   * Hyphenated CSS values like inline-block stay hyphenated.
   * The empty parentheses at the end are needed because of the way the
   * ReactDOMRe.Style.make() function was written.
   */
  let buttonStyle = ReactDOMRe.Style.make(~display="inline-block", ~marginLeft="1em", ~marginRight="1em", ());

  /*
   * In this JSX, the braces are used to interpolate a variable or expression.
   * You can’t put a string directly into JSX; instead, you must create a string
   * using React.string()
   */
  <main>
    {React.string("Simple counter with reducer")}
    <div>
      <button onClick={_ => dispatch(Decrement)} style={buttonStyle}>
        {React.string("Decrement")}
      </button>
      <span> {(userName ++ ", your count is " ++ (state.count |> string_of_int)) |> React.string} </span>
      <button onClick={_ => dispatch(Increment)} style={buttonStyle}>
        {React.string("Increment")}
      </button>
    </div>
  </main>;
};
