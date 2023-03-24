defmodule Cs491Hm1.OfficeAssets.Printer do
  use Ecto.Schema
  import Ecto.Changeset

  schema "printer" do
    field :building, :string
    field :inventory_code, :integer
    field :model, :string
    field :office_number, :integer

    timestamps()
  end

  @doc false
  def changeset(printer, attrs) do
    printer
    |> cast(attrs, [:model, :inventory_code, :office_number, :building])
    |> validate_required([:model, :inventory_code, :office_number, :building])
  end
end
