/* embed javascript magic */
%raw
"const identity = value => value";

[@bs.deriving abstract]
type configt = {
  tension: float,
  friction: float,
};

[@bs.deriving abstract]
type configDefaults = {
  default: configt,
  gentle: configt,
  wobbly: configt,
  stiff: configt,
  slow: configt,
};

type animatedValue;

type animValueOrFunction;

type makeAnimValueOrFunction = [
  | `FunctionVariant(unit => Js.Dict.t(animatedValue))
  | `AnimatedValuesVariant(Js.Dict.t(animatedValue))
];

[@bs.send]
external interpolateObj : (animatedValue, Js.t('a)) => animatedValue =
  "interpolate";

[@bs.send]
external interpolateFunc :
  (animatedValue, animatedValue => animatedValue) => animatedValue =
  "interpolate";

[@bs.val]
external makeAnimValueOrFunction :
  (
  [@bs.unwrap]
  [
    | `FunctionVariant(unit => Js.Dict.t(animatedValue))
    | `AnimatedValuesVariant(Js.Dict.t(animatedValue))
  ]
  ) =>
  animValueOrFunction =
  "identity";

let makeAnimValueOrFunction = makeAnimValueOrFunction;

/* unsafeAnim Values converter to std types */
external string_of_animatedValue : animatedValue => string = "%identity";

external float_of_animatedValue : animatedValue => float = "%identity";

external animatedValue_of_string : string => animatedValue = "%identity";

external animatedValue_of_float : float => animatedValue = "%identity";

[@bs.deriving abstract]
type propst = {
  [@bs.optional]
  from: Js.Dict.t(animatedValue),
  [@bs.as "to"] [@bs.optional]
  to_: animValueOrFunction,
  [@bs.optional]
  native: bool,
  [@bs.optional]
  config: configt,
  [@bs.optional]
  leave: animValueOrFunction,
  [@bs.optional]
  enter: animValueOrFunction,
  [@bs.optional]
  keys: Js.Array.t(string),
  [@bs.optional]
  immediate: bool,
  [@bs.optional]
  hold: bool,
  [@bs.optional]
  onRest: unit => unit,
  [@bs.optional]
  onFrame: Js.Dict.t(animatedValue) => unit,
  [@bs.optional]
  state: string,
  [@bs.optional]
  delay: int,
  [@bs.optional]
  className: string,
  /* [@bs.optional]
     render: Js.Dict.t(animatedValue) => ReasonReact.reactElement, */
};

[@bs.module "react-spring"]
external configDefaults : configDefaults = "config";

module Animated = {
  [@bs.deriving abstract]
  type animatedt = {
    a: ReasonReact.reactClass,
    abbr: ReasonReact.reactClass,
    address: ReasonReact.reactClass,
    area: ReasonReact.reactClass,
    article: ReasonReact.reactClass,
    aside: ReasonReact.reactClass,
    audio: ReasonReact.reactClass,
    b: ReasonReact.reactClass,
    base: ReasonReact.reactClass,
    bdi: ReasonReact.reactClass,
    bdo: ReasonReact.reactClass,
    big: ReasonReact.reactClass,
    blockquote: ReasonReact.reactClass,
    body: ReasonReact.reactClass,
    br: ReasonReact.reactClass,
    button: ReasonReact.reactClass,
    canvas: ReasonReact.reactClass,
    caption: ReasonReact.reactClass,
    cite: ReasonReact.reactClass,
    code: ReasonReact.reactClass,
    col: ReasonReact.reactClass,
    colgroup: ReasonReact.reactClass,
    data: ReasonReact.reactClass,
    datalist: ReasonReact.reactClass,
    dd: ReasonReact.reactClass,
    del: ReasonReact.reactClass,
    details: ReasonReact.reactClass,
    dfn: ReasonReact.reactClass,
    dialog: ReasonReact.reactClass,
    div: ReasonReact.reactClass,
    dl: ReasonReact.reactClass,
    dt: ReasonReact.reactClass,
    em: ReasonReact.reactClass,
    embed: ReasonReact.reactClass,
    fieldset: ReasonReact.reactClass,
    figcaption: ReasonReact.reactClass,
    figure: ReasonReact.reactClass,
    footer: ReasonReact.reactClass,
    form: ReasonReact.reactClass,
    h1: ReasonReact.reactClass,
    h2: ReasonReact.reactClass,
    h3: ReasonReact.reactClass,
    h4: ReasonReact.reactClass,
    h5: ReasonReact.reactClass,
    h6: ReasonReact.reactClass,
    head: ReasonReact.reactClass,
    header: ReasonReact.reactClass,
    hgroup: ReasonReact.reactClass,
    hr: ReasonReact.reactClass,
    html: ReasonReact.reactClass,
    i: ReasonReact.reactClass,
    iframe: ReasonReact.reactClass,
    img: ReasonReact.reactClass,
    input: ReasonReact.reactClass,
    ins: ReasonReact.reactClass,
    kbd: ReasonReact.reactClass,
    keygen: ReasonReact.reactClass,
    label: ReasonReact.reactClass,
    legend: ReasonReact.reactClass,
    li: ReasonReact.reactClass,
    link: ReasonReact.reactClass,
    main: ReasonReact.reactClass,
    map: ReasonReact.reactClass,
    mark: ReasonReact.reactClass,
    marquee: ReasonReact.reactClass,
    menu: ReasonReact.reactClass,
    menuitem: ReasonReact.reactClass,
    meta: ReasonReact.reactClass,
    meter: ReasonReact.reactClass,
    nav: ReasonReact.reactClass,
    noscript: ReasonReact.reactClass,
    [@bs.as "object"]
    object_: ReasonReact.reactClass,
    ol: ReasonReact.reactClass,
    optgroup: ReasonReact.reactClass,
    option: ReasonReact.reactClass,
    output: ReasonReact.reactClass,
    p: ReasonReact.reactClass,
    param: ReasonReact.reactClass,
    picture: ReasonReact.reactClass,
    pre: ReasonReact.reactClass,
    progress: ReasonReact.reactClass,
    q: ReasonReact.reactClass,
    rp: ReasonReact.reactClass,
    rt: ReasonReact.reactClass,
    ruby: ReasonReact.reactClass,
    s: ReasonReact.reactClass,
    samp: ReasonReact.reactClass,
    script: ReasonReact.reactClass,
    section: ReasonReact.reactClass,
    select: ReasonReact.reactClass,
    small: ReasonReact.reactClass,
    source: ReasonReact.reactClass,
    span: ReasonReact.reactClass,
    strong: ReasonReact.reactClass,
    style: ReasonReact.reactClass,
    sub: ReasonReact.reactClass,
    summary: ReasonReact.reactClass,
    sup: ReasonReact.reactClass,
    table: ReasonReact.reactClass,
    tbody: ReasonReact.reactClass,
    td: ReasonReact.reactClass,
    textarea: ReasonReact.reactClass,
    tfoot: ReasonReact.reactClass,
    th: ReasonReact.reactClass,
    thead: ReasonReact.reactClass,
    time: ReasonReact.reactClass,
    title: ReasonReact.reactClass,
    tr: ReasonReact.reactClass,
    track: ReasonReact.reactClass,
    u: ReasonReact.reactClass,
    ul: ReasonReact.reactClass,
    var: ReasonReact.reactClass,
    video: ReasonReact.reactClass,
    wbr: ReasonReact.reactClass,
    circle: ReasonReact.reactClass,
    clipPath: ReasonReact.reactClass,
    defs: ReasonReact.reactClass,
    ellipse: ReasonReact.reactClass,
    foreignObject: ReasonReact.reactClass,
    g: ReasonReact.reactClass,
    image: ReasonReact.reactClass,
    line: ReasonReact.reactClass,
    linearGradient: ReasonReact.reactClass,
    mask: ReasonReact.reactClass,
    path: ReasonReact.reactClass,
    pattern: ReasonReact.reactClass,
    polygon: ReasonReact.reactClass,
    polyline: ReasonReact.reactClass,
    radialGradient: ReasonReact.reactClass,
    rect: ReasonReact.reactClass,
    stop: ReasonReact.reactClass,
    svg: ReasonReact.reactClass,
    text: ReasonReact.reactClass,
    tspan: ReasonReact.reactClass,
  };
  [@bs.module "react-spring"] external animated : animatedt = "";
  external convertObjToStyle : 'a => ReactDOMRe.style = "%identity";
  let make = (~element=animated |. div, ~style, ~className=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=element,
      ~props=
        ReactDOMRe.props(~style=convertObjToStyle(style), ~className?, ()),
      children,
    );
};

module Trail = {
  [@bs.module "react-spring"]
  external reactClass : ReasonReact.reactClass = "Trail";
  let make = (~native=?, ~config=?, ~delay=?, ~from, ~to_, ~keys, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        propst(
          ~from,
          ~config?,
          ~delay?,
          ~to_=makeAnimValueOrFunction(to_),
          ~native?,
          ~keys,
          (),
        ),
      children,
    );
};

module Spring = {
  [@bs.module "react-spring"]
  external reactClass : ReasonReact.reactClass = "Spring";
  let make =
      (
        ~native=?,
        ~config=?,
        ~from,
        ~to_,
        ~delay=?,
        ~immediate=false,
        ~hold=false,
        /* ~render=?, */
        ~onRest=?,
        ~onFrame=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        propst(
          ~from,
          ~config?,
          ~to_=makeAnimValueOrFunction(to_),
          ~native?,
          ~immediate,
          ~hold,
          ~delay?,
          /* ~render?, */
          ~onRest?,
          ~onFrame?,
          (),
        ),
      children,
    );
};

module Transition = {
  [@bs.module "react-spring"]
  external reactClass : ReasonReact.reactClass = "Transition";
  let make =
      (
        ~from=?,
        ~native=?,
        ~config=?,
        ~enter=?,
        ~leave=?,
        ~keys=?,
        ~onRest=?,
        ~className=?,
        /* ~render=?, */
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        propst(
          ~from?,
          ~config?,
          ~native?,
          ~enter?,
          ~leave?,
          ~keys?,
          ~onRest?,
          ~className?,
          /* ~render?, */
          (),
        ),
      children,
    );
};

module Keyframes = {
  type statet;
  type reactSpringKeyFramest;
  /* more unsafe converts because why not :)  */
  /* unsafe converter to convert array of keyframes anim config to keyframesAnimConfig */
  external array : array(propst) => propst = "%identity";
  [@bs.module "react-spring"]
  external keyframes : reactSpringKeyFramest = "Keyframes";
  /* module type */
  [@bs.send]
  external spring :
    (reactSpringKeyFramest, Js.Dict.t(propst)) => ReasonReact.reactClass =
    "Spring";
  [@bs.send]
  external trail :
    (reactSpringKeyFramest, Js.Dict.t(propst)) => ReasonReact.reactClass =
    "Trail";
  [@bs.send]
  external transition :
    (reactSpringKeyFramest, Js.Dict.t(propst)) => ReasonReact.reactClass =
    "Transition";
  module Spring = {
    let make =
        (
          ~keyFramesAnimConfig: Js.Dict.t(propst),
          ~state,
          ~native=?,
          ~config=?,
          ~immediate=?,
          ~hold=?,
          /* ~render=?, */
          ~onRest=?,
          ~onFrame=?,
          children,
        ) =>
      ReasonReact.wrapJsForReason(
        ~reactClass=spring(keyframes, keyFramesAnimConfig),
        ~props=
          propst(
            ~state,
            ~config?,
            ~native?,
            ~immediate?,
            ~hold?,
            /* ~render?, */
            ~onRest?,
            ~onFrame?,
            (),
          ),
        children,
      );
  };
  module Trail = {
    let make =
        (
          ~keyFramesAnimConfig: Js.Dict.t(propst),
          ~state,
          ~native=?,
          ~config=?,
          ~keys,
          children,
        ) =>
      ReasonReact.wrapJsForReason(
        ~reactClass=trail(keyframes, keyFramesAnimConfig),
        ~props=propst(~state, ~config?, ~native?, ~keys, ()),
        children,
      );
  };
  module Transition = {
    let make =
        (
          ~keyFramesAnimConfig: Js.Dict.t(propst),
          ~state,
          ~native=?,
          ~config=?,
          ~keys,
          /* ~render=?, */
          children,
        ) =>
      ReasonReact.wrapJsForReason(
        ~reactClass=transition(keyframes, keyFramesAnimConfig),
        ~props=
          propst(
            ~state,
            ~config?,
            ~native?,
            ~keys,
            /* ~render?, */
            (),
          ),
        children,
      );
  };
};